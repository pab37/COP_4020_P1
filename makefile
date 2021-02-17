compiler : main.o parse.o lexer.o
	gcc -o compiler main.o parse.o  lexer.o -lm
lexer.o : lexer.c global.h
	gcc -c -Wall lexer.c
parse.o : parse.c global.h
	gcc -c -Wall parse.c
main.o : main.c global.h 
	gcc -c -Wall main.c
clean :
	rm compiler main.o parse.o lexer.o
