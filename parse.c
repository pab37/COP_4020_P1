#include "global.h"

void parse(char* str)
{
	printf("nparse %s\n",str);
	fp = fopen(str,"r");
	

	parseFile(fp, ";");
	
}

void parseFile(FILE *fp, char* delimiter)
{
	
}

int insert(char s[], int tokenVal)
{
	
}

int lookup(char s[])
{
	
}


