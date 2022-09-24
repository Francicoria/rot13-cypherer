CC = gcc
CFLAGS = -std=c99 -O2 -Wall -Wextra
SRC = rot13.c
EXE = rot13

all: clean compile run

clean:
	@rm -f "${EXE}"
	@printf "Removed previous executable\n"

compile:
	${CC} ${CFLAGS} ${SRC} -o ${EXE}
	@printf "Compiled to ./${EXE}\n\n"

run:
	./${EXE} "This is a ROT13 cypherer/decypherer."

.PHONY: all clean compile run
