CC = gcc
CFLAGS = -std=c99 -O2 -Wall -Wextra -Wpedantic
SRC = main.c
EXE = rot13

all: clean compile run

clean:
	rm -f "${EXE}"

compile:
	${CC} ${CFLAGS} ${SRC} -o ${EXE}

run:
	./${EXE} "This is a ROT13 cypherer/decypherer."

.PHONY: all clean compile run
