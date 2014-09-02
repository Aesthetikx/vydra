all: vydra

vydra: lex.yy.c token.o
	gcc lex.yy.c token.o -lfl -o vydra

lex.yy.c: vydra.l token.h
	flex vydra.l

token.o: token.c
	gcc -c token.c
