CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude

SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, objects/%.o, $(SRC))

all: rate edf

rate: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o rate

edf: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o edf

objects/%.o: src/%.c
	mkdir -p objects
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf objects rate edf

test-rate: rate
	./rate input.txt

test-edf: edf
	./edf input.txt