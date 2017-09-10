#include <stdio.h>
#include <string.h>
#include "aes.h"

#define LENGTH 1024

void XTSAES(const uint8_t[], const uint8_t[], uint8_t(*)[16], uint8_t(*)[16], const int, const char); 
void XTSAESBlock(const uint8_t[], const uint8_t[], uint8_t, uint8_t[], uint8_t[], const char); 

int main(int argc, char *argv[]){

	if((argc!=2 && argc!=3) || (strcmp(argv[1], "-d") && strcmp(argv[1], "-e")))
		printf("\nUsage: %s <-e/-d> [filename]\n", argv[0]); 
	else{
		uint8_t k1[16], k2[16];
		uint8_t input[LENGTH][16], output[LENGTH][16]; 
		FILE *fin;
		int i, j, len;

		if(argc==2)
			fin = fopen("input.txt", "r"); 
		else
			fin = fopen(argv[2], "r"); 

		// read the input file 
        /*
        for(i=0;!feof(fin);i++){
			for(j=0;!feof(fin)&&j<16; j++)
				fscanf(fin, "%X", &input[i][j]); 
		}
		len = i*16 - (17-j);
		fclose(fin); 
        */
		for(i=0, j=0; fscanf(fin, "%X", &input[i][j])!=EOF; j++){
			if(j==15){
				j = -1; 
				i++; 	
			}	
		}
		len = i*16 + j;
		fclose(fin);   

		// read the keys
		fin = fopen("key.txt", "r"); 
		for(i=0;i<16;i++)
			fscanf(fin, "%X", &k1[i]); 
		for(i=0;i<16;i++)
			fscanf(fin, "%X", &k2[i]); 
		fclose(fin); 

		// display the key 
		printf("Keys are: \n"); 
		printf("Key1: "); 
		for(i=0;i<16;i++)
			printf("%02X ", k1[i]); 
		printf("\nKey2: "); 
		for(i=0;i<16;i++)
			printf("%02X ", k2[i]); 
		printf("\n\n\n"); 

		// display the input file's text
		printf("The %d-bit %stext is: \n", len*8, strcmp(argv[1], "-e")?"cipher":"plain"); 
		for(i=0;i<(len-1)/16+1;i++){
			for(j=0;j<16&&i*16+j<len;j++)
				printf("%02X ", input[i][j]); 
			printf("\n");
		}	
		printf("\n\n"); 
		
		// do XTS-AES
		XTSAES(k1, k2, input, output, len, argv[1][1]);
		
		// display the output text
		printf("The %d-bit %stext is: \n", len*8, strcmp(argv[1], "-e")?"plain":"cipher"); 
		for(i=0;i<(len-1)/16+1;i++){
			for(j=0;j<16&&i*16+j<len;j++)
				printf("%02X ", output[i][j]); 
			printf("\n"); 
		}
		printf("\n\n"); 

	}
	return 0; 	
}


void swap(uint8_t *a, uint8_t *b){
	uint8_t tmp; 
	tmp = *a; 
	*a = *b; 
	*b = tmp; 
}

void swapArr(uint8_t a[], uint8_t b[]){
	int i; 
	for(i=0;i<16;i++)
		swap(&a[i], &b[i]); 
}

void XTSAES(const uint8_t key1[], const uint8_t key2[], uint8_t in[][16], uint8_t out[][16], const int len, const char mode){
	int i, j; 
	
	uint8_t m = (len-1)/16; 

	for(i=0;i<m-1;i++)
		XTSAESBlock(key1, key2, (uint8_t)i+1, in[i], out[i], mode); 

	if(mode=='e' || len%16==0)
		XTSAESBlock(key1, key2, (uint8_t)i+1, in[i], out[i], mode); 
	else if(mode=='d')
		XTSAESBlock(key1, key2, (uint8_t)m+1, in[i], out[i], mode); 
	i++; 	
	// Add CP
	for(j=0;j<16;j++){
		if(j>len-i*16-1)
			in[i][j] = out[i-1][j]; 
	}

	if(mode=='e' || len%16==0)
		XTSAESBlock(key1, key2, (uint8_t)i+1, in[i], out[i], mode); 
	else if(mode=='d')
		XTSAESBlock(key1, key2, (uint8_t)m, in[i], out[i], mode); 
	
	if(len%16!=0)
		swapArr(out[i], out[i-1]); 
}

void XTSAESBlock(const uint8_t key1[], const uint8_t key2[], uint8_t counter, uint8_t in[], uint8_t out[], const char mode){
	uint8_t tmp[16], buff[16], buffer[16], counters[16]; 
	int i; 

	memset(counters, 0, sizeof(counters)); 
	counters[15] = counter; 

	AES128_ECB_encrypt(counters, key2, tmp); 

	for(i=0;i<16;i++)
		buffer[i] = in[i]^tmp[i];

	if(mode=='e')
		AES128_ECB_encrypt(buffer, key1, buff); 
	else if(mode=='d')
		AES128_ECB_decrypt(buffer, key1, buff); 

	for(i=0;i<16;i++)
		out[i] = buff[i]^tmp[i]; 
}
