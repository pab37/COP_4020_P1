#ifndef LEXER_H
#define LEXER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
//#include "parse.h"
#include "symbol.h"
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

int IDIndex;
int NUMIndex;
int symbolIndex;
char numLexeme[100];
char idLexeme[100];
//int type;
FILE* input;

int lexan();
int lookup(char*);
void processFile(char*);
int getLine();
void display();
//void match(int t, char * message);

#endif
