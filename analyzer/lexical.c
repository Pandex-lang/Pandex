#ifndef LEXICAL_H
#include "lexical.h"
#endif

#ifndef _STDBOOL_H
# include <stdbool.h>
#endif

#ifndef _STDIO_H
# include <stdio.h>
#endif

#ifndef _STRING_H
# include <string.h>
#endif

#ifndef _STDLIB_H
# include <stdlib.h>
#endif

#ifndef SCANNER_H
# include "lexical/scanner.h"
#endif

size_t cur_line; // current line

void swap_tokenizer(int tok_id ,
struct Tokenizer *ptr){
  ptr->TOKEN = tok_id;
  ptr->prev->next = ptr;
  ptr->prev = ptr;
  ptr = ptr->next;
}

bool lex1line_str(char*str ,
/*struct Symbol_table *sym_tbl , */
struct Tokenizer *tokenner){
	char copy[strlen(str)]; // you don't can use pointers \
	you must use arrays instead :(

	strcpy(copy , str); // copy $str into $copy

	bool isKwd = true;
	bool isVar = false;
	bool mightPrintOrUnCompleteStringOnEmpty = false;

	int cur_kwd; // current keyword

	char *tok = strtok(copy , " ");
	while(tok != NULL)
	{
		// lex keywords
		if(tok[0] == '\"' || mightPrintOrUnCompleteStringOnEmpty){
			for(size_t i = 1; i < strlen(tok); i++){
				if(tok[i] != '"')
						fprintf(stdout,"%c",tok[i]);
			}


			printf("\n");
			goto endLoop;		
		}

		if(scan_kwd(tok) == -1)
			isKwd = false;

		if(isKwd)
		{
			cur_kwd = scan_kwd(tok);
			switch(cur_kwd){
				case RET_KWD:
        			swap_tokenizer(51 , tokenner); // 51 = RET
        			break;

				case CALL_KWD:
				swap_tokenizer(52 , tokenner); // 52 = CALL
				break;

				case INC_KWD:
        			swap_tokenizer(53 , tokenner); // INC = 53
        			break;

				case DEC_KWD:
				swap_tokenizer(54 , tokenner); // DEC = 54
				break;

				case VAR_KWD:
				swap_tokenizer(55 , tokenner); // VAR = 55
				break;

				case IF_KWD:
				swap_tokenizer(56 , tokenner); // IF = 56
				break;

				case ELSE_KWD:
				swap_tokenizer(57 , tokenner); // ELSE = 57
				break;

				case THEN_KWD:
				swap_tokenizer(58 , tokenner); // THEN = 58
				break;

				case FOR_KWD:
				swap_tokenizer(59 , tokenner); // FOR = 59
				break;

				case WHILE_KWD:
				swap_tokenizer(60 , tokenner); // WHILE = 60
				break;

			}
		}

		// end lex keywords

	endLoop:
	cur_kwd = 0; // empty cur_kwd variable
	tok = strtok(NULL , " ");
	} // end while
}

int main(int argc , char *argv[])
{
	struct Tokenizer tokenizer;

	if(argc != 2)
		return -1;

	FILE *fp = fopen(argv[1],"r");
	fseek(fp , 0 , SEEK_END);
	unsigned long int length = ftell(fp);
	rewind(fp);
	char *buf = malloc(length);
	fread(buf , 1 , length , fp);

	lex1line_str(buf , &tokenizer);
	perror("Lexer");
	puts("created but not executed else of print");
	return 0;
}
