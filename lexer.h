#ifndef LEXER_H
#define LEXER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
//#include "parse.h"
#include "symbol.h"
#define EOS '\0'
#define NUM 256
#define DIV 257
#define MOD 258
#define ID 259
#define BEGIN 300
#define END 301
#define DONE 260
#define NOT_FOUND 0
#define ERROR 401

int tokenVal;
static int lineNo = 1;
int IDIndex;
int NUMIndex;
int symbolIndex;
char numLexeme[100];
char idLexeme[100];
//int type;
FILE* input;

int lexan();
int lookup(char s[]);
void processFile(char*);
int getLine();
void display();
//void match(int t, char * message);

#endif
