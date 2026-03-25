CC = gcc

CFLAGS = -Wall -Wextra

EXECS = rate edf

all: $(EXECS)

rate: rate.c
	$(CC) $(CFLAGS) rate.c -o rate

edf: edf.c
	$(CC) $(CFLAGS) edf.c -o edf

clean:
	rm -f $(EXECS) *.out *.o