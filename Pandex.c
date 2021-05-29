// it's Pandex little version

// commands | statements
// inc
// dec
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc , char** argv)
{
	if(argc < 2){
		puts("./Pandex file.prefix");
		exit(0);
	}
	FILE *fp = fopen(argv[1] , "r");
	unsigned long int length;
	fseek(fp , 0 , SEEK_END);
	length = ftell(fp); // cur position of fp
	rewind(fp);

	char *buf = (char*) malloc (length);
	if(buf == NULL)
		exit(0);

	fread(buf , 1 , length  , fp);
	// puts(buf); // test
	char *tok = strtok(buf , "\n");
	char *src = (char*) malloc (sizeof(buf)); // empty source of tok
	unsigned long int src_i = 0;

	long int program = 0;
	while( tok != NULL){
		if(strcmp(tok , "inc") == 0)
			program++;
		else if(strcmp(tok , "dec") == 0)
			program--;

		tok = strtok(NULL , "\n");
	}

	printf("Program: %s executed successfully"
		"\nand result of main variable is"
		"\n$main: %ld\n" , argv[1] , program);

	return 0;
}

