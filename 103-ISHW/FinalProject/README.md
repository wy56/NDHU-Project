### Install:
	make

### Usage: 

**decrypt input.txt**	./XTS-AES.exe -d

**encrypt input.txt**	./XTS-AES.exe -e

**decrypt file**	./XTS-AES.exe -d fileName

**encrypt file**	./XTS-AES.exe -e fileName

### Config:

#### key.txt: 
##### (Hex) 16 bit for a line, need 2 lines
11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11

11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11

#### input.txt: 
##### (Hex) a bit for a group, can input 1024*16 bits. 
12 12 12 12 12 21 78 41 DA ..... 



