CFLAGS=-Wall -Wextra -Wpedantic -std=c11

all:
	rm -f app main.o process_file.o
	gcc ${CFLAGS} main.c lib/process_file.c -c	
	gcc ${CFLAGS} main.o process_file.o -o app
	rm -f main.o process_file.o
