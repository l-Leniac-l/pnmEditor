CC = g++
CFLAGS += -Wall -Os
CFDEBUG = -g3 -pedantic -Wall -Wunused-parameter -Wlong-long \
          -Wsign-conversion -Wconversion \
          -Wimplicit-function-declaration
CURSESFLAGS = -lncurses

SRCDIR = src
TARGET = bin
SRCEXT = cpp
CONSOLESRCS = ${SRCDIR}/mainT.${SRCEXT} ${SRCDIR}/filters.${SRCEXT} ${SRCDIR}/pnm.${SRCEXT}
TEXTUISRCS = ${SRCDIR}/mainUI.${SRCEXT} ${SRCDIR}/windows.cpp ${SRCDIR}/messenger.${SRCEXT} ${SRCDIR}/pnm.${SRCEXT} ${SRCDIR}/filters.${SRCEXT}
EXEC = pnmedit

all:
	@echo "Build started..."
	@mkdir -p ${TARGET}
	${CC} ${CONSOLESRCS} ${CFLAGS} -o ${TARGET}/${EXEC}
		${CC} ${TEXTUISRCS} ${CFLAGS} ${CURSESFLAGS} -o ${TARGET}/${EXEC}"UI"
	@echo "Build finished..."

console:
	@echo "Build started..."
	@mkdir -p ${TARGET}
	${CC} ${CONSOLESRCS} ${CFLAGS} -o ${TARGET}/${EXEC}
	@echo "Build finished..."

textui:
	@echo "Build started..."
	@mkdir -p ${TARGET}
	${CC} ${TEXTUISRCS} ${CFLAGS} ${CURSESFLAGS} -o ${TARGET}/${EXEC}"UI"
	@echo "Build finished..."

debug:
	${CC} ${CONSOLESRCS} ${CFLAGS} ${CFDEBUG} -o ${EXEC}

clean:
	@echo " Cleaning..."
	rm -rf ${TARGET}
