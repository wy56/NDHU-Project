#include <stdio.h>
#include <string.h>
#include <ctype.h>

void addkey(); 
void showkey(); 
void guess(); 
void decrypt(); 
void showfreq(); 
char key[26], exist[26]; 

int main(){

	char opt; 
	
	memset(key, 0, sizeof(key)); 
	memset(exist, 0, sizeof(exist)); 

	while(1) {
		printf("1. Add key. \n"); 
		printf("2. Guess. \n"); 
		printf("3. Decrypt the text file. \n"); 
		printf("4. Show key. \n");
		printf("5. Show frequency of each alphabet. \n");  
		printf("9. Exit. \n"); 	
		printf("You want to......? \n"); 
		printf("> "); 
		scanf(" %c", &opt); 
		if(opt=='1')
			addkey(); 
		else if(opt=='2')
			guess(); 
		else if(opt=='3')
			decrypt(); 
		else if(opt=='4')
			showkey(); 
		else if(opt=='5')
			showfreq(); 
		else if(opt=='9')
			break;
		else
			printf("Input error. \n"); 
	}	
	return 0; 	
}

void addkey(){
	int i; 
	char cipher[255], plaintext[255]; 
	printf("Input the cipher. \n"); 
	printf("> "); 
	scanf("%s", cipher); 
	printf("Input the plaintext. \n"); 
	printf("> "); 
	scanf("%s", plaintext); 
	if(strlen(cipher)!=strlen(plaintext))
		printf("Length of both text are different, back to menu. \n"); 
	else{
		for(i=0;i<strlen(cipher);i++){
			key[cipher[i]-'A'] = plaintext[i]; 	
			exist[plaintext[i]-'A'] = 1; 
			printf("%c -> %c\n", cipher[i], plaintext[i]); 
		}
	}
}

void showkey(){
	int i;
	for(i=0;i<26;i++)
		printf("%c ", 'A'+i); 
	printf("\n"); 
	for(i=0;i<26;i++){
		if(key[i]!=0)
			printf("%c ", key[i]);
		else
			printf("_ "); 
	}
	printf("\n");  	
}

void showfreq(){
	char filename[255], c;
	FILE *fin;
 	int i, j, max;
	struct _node{
		int count; 
		char alpha; 	
	} node[26], tmp; 
	 
	printf("Input the file name. \n");
	printf("> ");
	scanf("%s", filename);

	for(i=0;i<26;i++){
		node[i].count = 0; 
		node[i].alpha = 'A'+i; 	
	}

	fin = fopen(filename, "r"); 
	c = fgetc(fin); 
	while(c!=EOF){
		if(isalpha(c))
			node[c-'A'].count++; 	
		c = fgetc(fin); 
	}
	fclose(fin); 

	for(i=0;i<26;i++){
		max = i; 
		for(j=i+1;j<26;j++){
			if(node[max].count<node[j].count)
				max = j; 
		}	
		tmp.alpha = node[max].alpha; 
		node[max].alpha = node[i].alpha; 
		node[i].alpha = tmp.alpha;
		tmp.count = node[max].count; 
		node[max].count = node[i].count; 
		node[i].count = tmp.count;  
	}

	for(i=0;i<26;i++){
		printf("%c: %d\t", node[i].alpha, node[i].count); 
		if(i%10==9)
			printf("\n"); 
	}
	printf("\n"); 

}

void output(char *now, char *cipher){
	char str[255]; 
	int i, len;
	len = strlen(now);  
	if(len>=strlen(cipher))
		printf("%s ", now); 
	else if(key[cipher[len]-'A']!=0){
		strcpy(str, now); 
		str[strlen(now)] = key[cipher[len]-'A']; 
		str[strlen(now)+1] = '\0'; 
		output(str, cipher); 
	}
	else{
		for(i=0;i<len;i++){
			if(cipher[i]==cipher[len]){
				strcpy(str, now); 
				str[len] = str[i]; 
				str[len+1] = '\0'; 
				output(str, cipher); 	
				break;
			}
		}
		if(i==len) {
			for(i=0;i<26;i++){
				if(exist[i])
					continue; 
				strcpy(str, now); 
				str[len] = i+'A'; 
				str[len+1] = '\0'; 
				output(str, cipher); 	
			}	
		}
	}
}

void guess(){
	char guess[255], str[255]; 
	int i, j; 
	printf("Input the cipher string you want to guess. \n"); 
	printf("> "); 
	scanf("%s", guess); 
	strcpy(str, ""); 
	output(str, guess);
	printf("\n");  
}

void decrypt(){
	char filename[255], defilename[258], c; 
	FILE *fin, *fout; 
	printf("Input the file name. \n"); 
	printf("> "); 
	scanf("%s", filename); 
	strcpy(defilename, "de-"); 
	strcat(defilename, filename); 
	fin = fopen(filename, "r");
	fout = fopen(defilename, "w"); 
	
	c = fgetc(fin); 
	while(c != EOF){
		if(isalpha(c)){
			if(key[c-'A'])
				fputc(key[c-'A'], fout); 
			else
				fputc('_', fout); 
		}	
		else
			fputc(c, fout); 
		c = fgetc(fin); 
	}
	fclose(fin); 
	fclose(fout); 
}
