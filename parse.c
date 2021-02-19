#include "parse.h"

void parse(char* str)
{
	printf("nparse %s\n",str);
	fp = fopen(str,"r");
	
	parseFile(fp, delimiter);
	
}

void parseFile(FILE *fp, char* delimiter)
{
	
}

/*The structure of Number and Identifier

 *You should detect whether or not a character string comprises an integer.

 *These are valid numbers:
     123, 1234567, 456789, etc ...
	 
 *A legal <identifier> will start with a letter 
 *followed by combinations of letters, numbers, 
 *and underscores, subject to the following two rules:
 *
 * 1) You cannot have consecutive underscores
 * 2) An identifier cannot end with an underscore.
 * 
 * if a ~ is found ignore the line 
*/

void showLexemes()
{
	
}

int lookup(char s[])
{
	
}

void match(int t, char * message)
{
	if(lookahead == t)
	{
		lookahead = lexan();
	}else
	{
		//printf("syntax error");
		error("syntax error");
	}
}

//ramonda 228-436-7434 , lori 228-436-7401 VA0008559212
