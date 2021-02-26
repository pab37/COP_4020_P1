#include "parse.h"

void statement()
{
	printf("in statement");
	lookahead = lexan();

	match(BEGIN, "Missing \"begin\" statement.\n");

	while(lookahead != END)
	{
		AssignStmt();
	}

	match(END, "Missing \"end.\".\n");
	match('.', "Missing \".\" symbol.\n");

	if(lookahead == EOF)
	{
		printf("success.\n");
		printf("\n");
		printf("Symbols Identified:\n\n");
		printf("Token\tToken Value\n");

		for(int i = 0; i < 100; ++i)
		{
			if(symTable[i].value != 0)
			{
				printf("%s\t%d\n", symTable[i].name, symTable[i].value);
			}
		}
	}
}

void AssignStmt()
{
	match(ID, "Only identifiers are allowed here.\n");
	match(lookahead, "Missing \"=\" operator.\n");
	expression();
	match(';', "Missing \";\" symbol.\n");
}

void expression()
{
	term();

	while((lookahead) == '+' || (lookahead == '-'))
	{
		match(lookahead, "Missing \"+\" or \"-\" operator.\n");
		term();
	}
}

void term()
{
	factor();

	while(lookahead == '*' || lookahead == '/')
	{
		match(lookahead, "Missing \"*\" or \"/\" operator.\n");
		factor();
	}
}

void factor()
{
	if(lookahead == ID)
	{
		match(ID, "Expected an indentifier here.\n");
	}else if(lookahead == NUM)
	{
		match(NUM, "Expected a number here.\n");
	}else if(lookahead == '(')
	{
		match('(', "Missing \"(\" symbol.\n");

		expression();

		match(')', "Missing \")\" symbol.\n");	
	}
}

void match(int t, char * message)
{
	if(lookahead == t)
	{
		lookahead = lexan();
	}else
	{
		printf("ERROR on line %d: %s", getLine(), message);
		
		if(lookahead == ERROR)
		{
			printf("ERROR: Identifiers can not end with \"_\".\n");
		}
		exit(-1);
	}
}