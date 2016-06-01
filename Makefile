CC = g++
CFLAGS += -Wall -Os
CFDEBUG = -g3 -pedantic -Wall -Wunused-parameter -Wlong-long \
          -Wsign-conversion -Wconversion \
          -Wimplicit-function-declaration

EXEC = pnmedit
SRCS = main.cpp filters.cpp pnm.cpp

all:
	${CC} ${SRCS} ${CFLAGS} -o ${EXEC}

debug:
	${CC} ${SRCS} ${CFLAGS} ${CFDEBUG} -o ${EXEC}

clean:
	rm -rf ./${EXEC}
