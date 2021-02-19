compiler : main.o parse.o lexer.o symbol.o
	gcc -o compiler main.o parse.o  lexer.o symbol.o -lm
symbol.o : symbol.c symbol.h
	gcc -c -Wall symbol.c
lexer.o : lexer.c lexer.h
	gcc -c -Wall lexer.c
parse.o : parse.c parse.h
	gcc -c -Wall parse.c
main.o : main.c 
	gcc -c -Wall main.c
clean :
	rm compiler main.o parse.o lexer.o symbol.o
