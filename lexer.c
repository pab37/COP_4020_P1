#include "lexer.h"

int lexan()
{
	char ch;
	
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
			/*begin
				get the identifier into idlexeme
				typer = lookup(ID);
				if(type == NOT_FOUND)
				{
					insert value into symbolTable
					return ID;
				}else
				{
					return type;
				}
				end
			*/
		}else if(ch == EOF)
		{
			return DONE;
		}else
		{
			return ch;
		}
		//end while loop 
	}
	//end lexan
}

void match(int t, char * message)
{
	
}

void showLexemes()
{
	
}