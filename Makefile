CC = g++
CFLAGS += -Wall -Os
CFDEBUG = -g3 -pedantic -Wall -Wunused-parameter -Wlong-long \
          -Wsign-conversion -Wconversion \
          -Wimplicit-function-declaration

LFLAGS += -I./include/

SRCDIR = src
TARGET = bin

EXEC = pnmedit

all:
	${CC} ${LFLAGS} ${SRCDIR}/main.cpp ${SRCDIR}/filters.cpp \
		${SRCDIR}/file.cpp ${CFLAGS} -o ${TARGET}/${EXEC}

clean:
	rm -rf ./${EXEC}
