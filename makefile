CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude

SRC = src/main.c src/task.c
OBJ = objects/main.o objects/task.o

all: rate edf

rate: CFLAGS += -DRATE
rate: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o rate

edf: CFLAGS += -DEDF
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