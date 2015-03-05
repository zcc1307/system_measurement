CC=gcc
CFLAGS=-O0 -Wall
debug: CC += -DDEBUG -g
debug: main

main: main.o test_fcn.o
	$(CC) $(CFLAGS) -o main main.o test_fcn.o  -pthread
	
main.o: main.c test_fcn.h
	$(CC) $(CFLAGS) -c main.c
    
test_fcn.o: test_fcn.c test_fcn.h
	$(CC) $(CFLAGS) -c test_fcn.c   

clean:
	- rm *.o
	- rm main

