#ifndef LEXER_H
#define LEXER_H
#include "parse.h"
#include "symbol.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int tokenVal;
int lineNo = 1;
int IDIndex = 0;
int NUMIndex = 0;
int symbolIndex = 0;
int numLexeme[100];
int idLexeme[100];
int type;
FILE* input;

struct entry symTable[1000];

int lexan();
int lookup(char s[]);
void processFile(char*);
int getLine();
//void match(int t, char * message);

#endif
