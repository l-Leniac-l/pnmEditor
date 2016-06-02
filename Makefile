CC = g++
CFLAGS += -Wall -Os
CFDEBUG = -g3 -pedantic -Wall -Wunused-parameter -Wlong-long \
          -Wsign-conversion -Wconversion \
          -Wimplicit-function-declaration

EXECT = pnmedit
EXECUI = pnmeditUI
SRCS = main.cpp filters.cpp pnm.cpp
SRCSUI = main2.cpp windows.cpp messenger.cpp pnm.cpp filters.cpp

all:
	${CC} ${SRCS} ${CFLAGS} -o ${EXECT}
	${CC} ${SRCSUI} ${CFLAGS} -lncurses -o ${EXECUI}

console:
	${CC} ${SRCS} ${CFLAGS} -o ${EXECT}

textui:
	${CC} ${SRCSUI} ${CFLAGS} -lncurses -o ${EXECUI}

debug:
	${CC} ${SRCS} ${CFLAGS} ${CFDEBUG} -o ${EXECT}

clean:
	rm -rf ./${EXECT}
	rm -rf ./${EXECUI}
