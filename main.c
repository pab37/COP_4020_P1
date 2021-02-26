#include <stdio.h>
#include <string.h>
//#include "lexer.h"
//#include "parse.h"

int main(int argc, char* argv[])
{
	processFile(argv[1]);
	statement();
	
	return 0;
}
