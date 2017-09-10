# A Modified XTS-AES Encryption and Decryption
### Input File: input.exe and key.txt
### Time Limit: No

## Problem Description
Advanced Encryption Standard (AES) is a well-known synnetric block cipher in modern crytography. It was published by NIST in 2001. Here, we design a modified XTS-AES as shown in Fig.1. Please write rwo programs for encryption and decryption (e.g., encrypt.cpp and decrypt.cpp). To test the correctness of your encryption and decryption, two samples (one 256-bit plaintext and one 192-bit plaintext) with 128-bit Key1 and 128-bit Key2 (please see Input File in Hex format), and 256-bit ciphertext and 192-bit ciphertext (please see Output File in Hex format) are given. Notice that, in your program, please use the value (i+1) for counter i, i.e., the values of counter 0 and counter 1 are 1 and 2, respectively, for the test samples. 

## Input File Format
There are two input files: one is input.txt (the paintextr or ciphertext) for encryption and decryption, and the other is ket.txt to store modified XTS-AES\'s key. The input.txt contains n-bit with Hex format. Also, the first line (respectively, second line) in key.txt is 128-bit Key1 (respectively, Key2) with Hex format. 

## Output Format
n-bit plaintext (or ciphertext) in Hex format shown on screen. 

## Sample Input
### (for encryption)

#### Sample 1: 256-bit plaintext
##### Input.txt: 
01 23 45 67 89 AB CD EF FE DC BA 98 76 54 32 10 01 23 45 67 89 AB CD EF FE DC BA 98 76 54 32 10
##### Key.txt: 
0F 15 71 C9 47 D9 E8 59 0C B7 AD D6 AF 7F 67 98

89 76 F7 FA 6D DA 7B C0 95 8E 9D 74 9C 17 51 F0

#### Sample 2: 192-bit plaintext
##### Input.txt: 
01 23 45 67 89 AB CD EF FE DC BA 98 76 54 32 10 01 23 45 67 89 AB CD EF
##### Key.txt: 
0F 15 71 C9 47 D9 E8 59 0C B7 AD D6 AF 7F 67 98

89 76 F7 FA 6D DA 7B C0 95 8E 9D 74 9C 17 51 F0

### (for decryption)

#### Sample 1: 256-bit plaintext
##### Input.txt: 
9B 19 21 F8 77 0E 46 B9 E4 FB BB B4 3E 9A F6 05 F1 C4 FD B5 0C 35 AF 98 24 4D 66 62 DA 35 26 53
##### Key.txt: 
0F 15 71 C9 47 D9 E8 59 0C B7 AD D6 AF 7F 67 98

89 76 F7 FA 6D DA 7B C0 95 8E 9D 74 9C 17 51 F0

#### Sample 2: 192-bit plaintext
##### Input.txt: 
3E AD 3E B4 5A 0C 10 D1 8F 55 FB BF 0B 45 7E 8A 9B 19 21 F8 77 0E 46 B9
##### Key.txt: 
0F 15 71 C9 47 D9 E8 59 0C B7 AD D6 AF 7F 67 98

89 76 F7 FA 6D DA 7B C0 95 8E 9D 74 9C 17 51 F0

## Output for the Sample Input
### (for encryption)

#### Sample 1: 256-bit ciphertext
9B 19 21 F8 77 0E 46 B9 E4 FB BB B4 3E 9A F6 05 F1 C4 FD B5 0C 35 AF 98 24 4D 66 62 DA 35 26 53
#### Sample 2: 192-bit ciphertext
3E AD 3E B4 5A 0C 10 D1 8F 55 FB BF 0B 45 7E 8A 9B 19 21 F8 77 0E 46 B9

### (for decryption)

### Sample 1: 256-bit plaintext
01 23 45 67 89 AB CD EF FE DC BA 98 76 54 32 10 01 23 45 67 89 AB CD EF FE DC BA 98 76 54 32 10

### Sample 2: 192-bit plaintext
01 23 45 67 89 AB CD EF FE DC BA 98 76 54 32 10 01 23 45 67 89 AB CD EF

