run : main.o parse.o lexer.o emitter.o symbol.o error.o init.o
	gcc -o run main.o parse.o lexer.o emitter.o symbol.o error.o init.o -lm 
parse.o : parse.c global.h
	gcc -c -Wall parse.c
lexer.o : lexer.c global.h
	gcc -c -Wall lexer.c
emitter.o : emitter.c global.h
	gcc -c -Wall emitter.c
error.o : error.c global.h
	gcc -c -Wall error.c
init.o : init.c global.h
	gcc -c -Wall init.c
symbol.o : symbol.c global.h
	gcc -c -Wall symbol.c
main.o : main.c global.h 
	gcc -c -Wall main.c
clean :
	rm run main.o parse.o