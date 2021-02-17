#include "global.h"
#include <ctype.h>

void showLexemes()
{
	
}

int lexan()
{
	char ch;
	//find BEGIN
	while(1)
	{
		ch = getchar();
		if(ch == ' ' || ch == '\t')
		{
			;//do nothing
		}else if(ch == '\n')
		{
			lineNo++;
		}else if(isdigit(ch))
		{
			printf("found digit");
			/*begin
				get the number into numLexeme
				return NUM;
				end
			*/
		
		}else if(isalpha(ch))
		{
			printf("found a letter");
		}
		
		
	}
}
