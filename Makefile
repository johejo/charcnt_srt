CC = gcc
PROGRAM=charcnt_srt
CFLAGS = -Wall -g
OBJS = main.o count.o sort.o
$(PROGRAM) : $(OBJS)
	$(CC) $(OBJS) -o $(PROGRAM)
main.o : main.c defs.h
	$(CC) -c $(CFLAGS) main.c

sort.o : sort.c defs.h
	$(CC) -c $(CFLAGS) sort.c

count.o : count.c defs.h
	$(CC) -c $(CFLAGS) count.c

clean:
	-rm -rf $(PROGRAM) $(OBJS) $(PROGRAM).exe
