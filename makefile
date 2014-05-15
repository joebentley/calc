CC=gcc
CFLAGS=-Wall
SOURCES=calc.c parser.c utils.c
EXECUTABLE=calc

all:
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE)

debug:
	$(CC) $(CFLAGS) $(SOURCES) -g -o $(EXECUTABLE)debug
	
