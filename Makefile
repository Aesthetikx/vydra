all: vydra

vydra: lex.yy.c token.o hash_table.o
	gcc lex.yy.c token.o hash_table.o -lfl -o vydra

lex.yy.c: vydra.l token.h
	flex vydra.l

token.o: token.c token.h
	gcc -c token.c

hash_table.o: hash_table.c hash_table.h
	gcc -c hash_table.c

clean:
	rm *.o vydra lex.yy.c
