#ifndef SYMBOL_H
#define SYMBOL_H
#include "lexer.h"


typedef struct entry
{
	char name[100];
	int value;
}entry;

void setName(char*);
char* getName();
void setValue(int);
int getValue();

#endif
