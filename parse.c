#include "global.h"

void parse()
{
	char str[20];
	printf("Enter the name of the file you would like to scan: ");
	scanf("%s",&str);
	
	fp = fopen(str,"r");
	
	if(fp == NULL)
	{
		printf("could not open file %s",str);//error for wrong file name or nonexistant file.
		exit(1);
	}else
	{
		printf("%s has been opened successfully!!", str);//test to ensure file opened successfully.
	}
	
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


