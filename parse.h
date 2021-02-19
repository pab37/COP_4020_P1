#ifndef PARSE_H
#define PARSE_H
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
char expression[500];
const char delimiter [] = " ~;.";
char *token;

FILE * fp;

/*struct entry
{
	char *lexPtr;
	int token;
};*/

void parse(char*);
void match(int t, char * message);
//int lookup(char s[]);
void showLexemes();
void parseFile(FILE *fp, char* delimiter);
	
#endif

