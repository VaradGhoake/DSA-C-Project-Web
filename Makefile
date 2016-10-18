CC = gcc

#CFLAGS  = -g -Wall

wget: wget.c connect.c ConvertLinks.c
	$(CC)  -o wget wget.c connect.c ConvertLinks.c

clean:
	$(RM) wget
