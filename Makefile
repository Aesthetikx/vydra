APPNAME = bin/vydra
CC = gcc
SOURCEDIR = src
OBJDIR = obj
SOURCES := $(wildcard src/*.c)
OBJECTS := $(patsubst src%,obj%, $(patsubst %.c,%.o, $(SOURCES))) obj/lex.yy.o

all: $(OBJECTS)
	$(CC) -o $(APPNAME) $(OBJECTS) -lfl

src/lex.yy.c: src/vydra.l
	flex -osrc/lex.yy.c src/vydra.l

obj/%.o: src/%.c
	$(CC) -o $@ -c $<

clean:
	-rm -r obj/*.o
	-rm $(APPNAME)
	-rm src/lex.yy.c
