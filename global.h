#ifndef GLOBAL_H
#define GLOBAL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EOS '\0'
#define NUM 256
#define DIV 257
#define MOD 258
#define ID 259
#define BEGIN 300
#define END 301
#define DONE 260
#define NOT_FOUND 0	

int tokenVal;
int lineNo;
int lookahead;

FILE * fp;

struct entry
{
	char *lexPtr;
	int token;
};

struct entry symTable[1000];
char expression[500];

void showError(char *, int);
void parse();
int insert(char s[], int);
int lookup(char s[]);
void emit(int, int);
void init();
void showLexemes();
void parseFile(FILE *fp, char* delimiter);
	
#endif

