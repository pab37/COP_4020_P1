#include "parse.h"
//#include "lexer.h"

void statement()
{
	//printf("in statement");
	lookahead = lexan();

	match(BEGIN, "Missing \"begin\" statement.\n");

	while(lookahead != END)
	{
		match(ID, "Only identifiers can be assigned here");
		match('=',"Missing the \"=\" operator.\n" );
		expression();
		match(';', "Missing \";\" symbol.\n");
			
	}

	match(END, "Missing \"end.\".\n");
	match('.', "Missing \".\" symbol.\n");

	if(lookahead == EOF)
	{
		printf("success.\n");
		display();
	}
}

/*
void AssignStmt()
{
	match(ID, "Only identifiers are allowed here.\n");
	match('=', "Missing \"=\" operator.\n");
	expression();
	match(';', "Missing \";\" symbol.\n");
}
*/

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
		printf(" ERROR on line %d: %s", getLine(), message);
		
		if(lookahead == ERROR)
		{
			printf(" ERROR: Identifiers can not end with \"_\".\n");
		}
		exit(-1);
	}
}
