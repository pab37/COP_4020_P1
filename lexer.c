#include "lexer.h"

void processFile(char *fp)
{
	printf("opening file");
	input = fopen(fp,"r+");
}

int lexan()
{
	char ch;
	
	while(true)
	{
		ch = fgetc(input);
		if(ch == ' ' || ch == '\t')
		{
			continue;//do nothing

		}else if(ch == '\n')
		{
			lineNo++;
			continue;

		}else if(ch == '~')
		{
			while(ch != '\n')
			{
				ch = fgetc(input);
			}
			ungetc(ch, input);
			++lineNo;
			continue;

		}else if(isdigit(ch))
		{
			printf("found digit");
			while(isdigit(ch))
			{
				ungetc(ch, input); //ch = getchar();
				fscanf(input, "%d", &tokenVal);
				numLexeme[NUMIndex] = tokenVal;
				++NUMIndex;
			}
			return NUM;

		}else if(isalpha(ch))
		{
			printf("found a letter");
			while(isalpha(ch))
			{
				 //ch = getchar();
				idLexeme[IDIndex] = ch;
				++IDIndex;
				while((isalnum(ch)) || (ch == '_'))
				{
					ch = fgetc(input);
					idLexeme[IDIndex] = ch;
					++IDIndex;
				}
			}
			ungetc(ch, input);
			idLexeme[IDIndex - 1] = '\0';
			type = lookup(idLexeme);

			if(type == ID)
			{
				strcpy(symTable[symbolIndex].name, idLexeme);
				symTable[symbolIndex].value = ID;//insertValue into symbolTable;
				++symbolIndex;

			}else if(type == BEGIN)
			{
				strcpy(symTable[symbolIndex].name, idLexeme);
				symTable[symbolIndex].value = BEGIN;//insertValue into symbolTable;
				++symbolIndex;
				
			}else if(type == END)
			{
				strcpy(symTable[symbolIndex].name, idLexeme);
				symTable[symbolIndex].value = END;//insertValue into symbolTable;
				++symbolIndex;
				
			}
			return type;
		}else if(ch == EOF)
		{
			return DONE;
		}else
		{
			return ch;
		}//end while loop 
	}
	//end lexan
}


int lookup(char s[])
{
	if(s[IDIndex - 2] == '_')
	{
		return ERROR;
	}else if(s == "begin")
	{
		return BEGIN;
	}else if(s == "end.")
	{
		return END;
	}else
	{
		return ID;			
	}
}

int getLine()
{
	return lineNo;
}
