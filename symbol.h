#ifndef SYMBOL_H
#define SYMBOL_H
#include "lexer.h"


struct entry symTable[1000];
int lookup(char s[]);
int insert(char s[]);
//char expression[500];

#endif