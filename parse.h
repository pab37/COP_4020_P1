#ifndef PARSE_H
#define PARSE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lexer.h"
#define NUM 256
#define DIV 257
#define MOD 258
#define ID 259
#define BEGIN 300
#define END 301
#define DONE 260
#define NOT_FOUND 0
#define ERROR 401

int lookahead;
char *token;

void match(int t, char * message);
void statement();
//void AssignStmt();
void expression();
void term();
void factor();
	
#endif

