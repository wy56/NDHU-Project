main: src/main.o aes.o
	gcc src/main.o src/aes.o -o XTS-AES.exe -Wall -Wshadow -O2

main.o: src/aes.h src/main.c
	gcc -c main.c -o src/main.o -Wall -Wshadow -O2

aes.o: src/aes.h src/aes.c
	gcc -c src/aes.c -o src/aes.o -Wall -Wshadow -O2

# clean
clean: 
	rm src/*.o XTS-AES.exe
