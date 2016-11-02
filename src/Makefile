CC = gcc

#CFLAGS  = -g -Wall

program: main.o client.o recursive.o headers.o
	$(CC)  -o program main.o client.o recursive.o headers.o http.o

main.o: headers.c headers.h main.c
	$(CC) -c main.c headers.c headers.h

client.o: client.c client.h http.c css.c css.h http.h
	$(CC) -c client.c client.h http.c headers.h headers.c

recursive.o: recursive.c recursive.h recur.c http.c http.h
	$(CC) -c recursive.c recursive.h recur.c headers.h headers.c

headers.o: 
	$(CC) -c headers.c headers.h

http.o: http.c http.h
	$(CC) -c http.c http.h

clean:
	-$(RM) *.o

