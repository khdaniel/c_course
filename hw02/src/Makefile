CFLAGS=-Wall -Wextra -Wpedantic -std=c11

all:
	rm -f app main.o convert.o cmd.o utils.o
	gcc ${CFLAGS} main.c lib/convert/convert.c -c	
	gcc ${CFLAGS} main.c lib/cmd/cmd.c -c		
	gcc ${CFLAGS} main.c lib/utils/utils.c -c	
	gcc ${CFLAGS} main.o convert.o cmd.o utils.o -o app
	rm -f main.o convert.o cmd.o utils.o
