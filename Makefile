CC = gcc
CCFlags = -std=c99 -Wall -Werror

all: bindec quad seq MyFloat

bindec: bindec.c
	$(CC) $(CCFlags) bindec.c -o bindec

quad: quad.c
	$(CC) $(CCFlags) quad.c -lm -o quad

seq: seq.c
	$(CC) $(CCFlags) seq.c -o seq

MyFloat: MyFloat.c
	$(CC) $(CCFlags) MyFloat.c -o MyFloat

clean:
	rm -f bindec quad seq MyFloat
