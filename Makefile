CC = g++
CFLAGS += -Wall -Os -std=c++0x
CFDEBUG = -g3 -pedantic -Wall -Wunused-parameter -Wlong-long \
          -Wsign-conversion -Wconversion \
          -Wimplicit-function-declaration

LFLAGS += -I./include/

SRCDIR = src
TARGET = bin

EXEC = pnmedit

all:
	@echo "Build process started..."
	@${CC} ${LFLAGS} ${SRCDIR}/main.cpp ${SRCDIR}/filters.cpp \
		${SRCDIR}/file.cpp ${CFLAGS} -o ${TARGET}/${EXEC}
	@echo "Build process finished..."
clean:
	@echo "Clean process started..."
	@rm -rf ./${EXEC}
	@echo "Clean process finished..."
