all: vydra

vydra: lex.yy.c token.o hash_table.o member_table.o object.o
	gcc lex.yy.c token.o hash_table.o -lfl -o vydra

lex.yy.c: vydra.l token.h
	flex vydra.l

token.o: token.c token.h
	gcc -c token.c

object.o: object.c object.h
	gcc -c object.c

env.o: env.c env.h
	gcc -c env.c

hash_table.o: hash_table.c hash_table.h
	gcc -c hash_table.c

member_table.o: member_table.c member_table.h
	gcc -c member_table.c

clean:
	rm *.o vydra lex.yy.c
