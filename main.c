#include <stdio.h>
#include "parse.h"
#include "lexer.h"
#include "symbol.h"

int main(int argc, char* argv[])
{
	processFile(argv[1]);
	statement();
	
	return 0;
}
