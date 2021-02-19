#ifndef LEXER_H
#define LEXER_H
#include "parse.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int tokenVal;
int lineNo;
int lookahead;

struct entry
{
	char *lexPtr;
	int token;
};

struct entry symTable[1000];
//char expression[500];

int lexan();
//int lookup(char s[]);
void match(int t, char * message);

#endif
