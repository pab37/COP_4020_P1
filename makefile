compiler : main.o parse.o lexer.o
	gcc -o compiler main.o parse.o  lexer.o -lm
lexer.o : lexer.c lexer.h
	gcc -c -Wall lexer.c
parse.o : parse.c parse.h
	gcc -c -Wall parse.c
main.o : main.c 
	gcc -c -Wall main.c
clean :
	rm main.o parse.o lexer.o
