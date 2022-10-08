#!/bin/sh

CC="gcc"
CFLAGS="-std=c99 -O2 -Wall -Wextra -Wpedantic"
SRC="rot13.c"
EXE="rot13"

set -xe

rm -f ${EXE}
exec ${CC} ${CFLAGS} ${SRC} -o ${EXE}
