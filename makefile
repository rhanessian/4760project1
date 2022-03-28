CC	= gcc
CFLAGS	= -ggdb3
CPPFLAGS= -DDEBUG=1

.SUFFIXES:
.SUFFIXES: .c .o

.c.o:
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $<

%.o: %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

clean:
	rm *.o simplechain
