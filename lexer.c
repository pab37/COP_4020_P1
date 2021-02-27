#include "lexer.h"
//#include "symbol.h"

entry symTable[1000];
int lineNo = 1;
int IDIndex = 0;
void processFile(char *file)
{
	//printf("opening file");
	input = fopen(file,"r+");
	printf("file name = %s\n",file);
}

int lexan()
{
	char ch;
	
	while(true)
	{
		ch = fgetc(input);
		IDIndex = 0;
		//printf(" Start of lexan(), ch = %c\n", ch);
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
			//printf("found digit ");
			ungetc(ch, input); //ch = getchar();
			fscanf(input, "%d", &tokenVal);
			numLexeme[NUMIndex] = tokenVal;
			++NUMIndex;
			
			return NUM;

		}else if(isalpha(ch))
		{	
			int type;
			IDIndex = 0;
			//printf("found a letter ");
			idLexeme[IDIndex] = ch;
			++IDIndex;
			while((isalnum(ch)) || (ch == '_'))
			{
				
				ch = fgetc(input);
				idLexeme[IDIndex] = ch;
				++IDIndex;
			}
		
			ungetc(ch, input);
			//IDIndex = 0;
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
		}else
		{
			return ch;
		}//end while loop 
	}
	//end lexan
}


int lookup(char* s)
{
	if(s[IDIndex - 2] == '_')
	{
		return ERROR;
	}else if(strcmp(s, "begin") == 0)
	{
		return BEGIN;
	}else if(strcmp(s, "end") == 0)
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

void display()
{
	printf("\n");
	printf("Symbols Identified:\n\n");
	printf("Token\tToken Value\n");

	for(int i = 0; i < 1000; ++i)
	{
		if(symTable[i].value != 0)
		{
			printf("%s\t%d\n", symTable[i].name, symTable[i].value);
		}
	}
}
