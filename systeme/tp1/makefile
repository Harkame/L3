CC=gcc
CFLAGS=-Wall -std=c99

.c:
	$(CC) $(CFLAGS) -o $@  $<
.o:
	$(CC) $(CFLAGS) -o $@  $<

.c.o:
	$(CC) $(CFLAGS) -c $<



e14 : e14.c
	gcc -Wall e14.c -o e14
	e14
