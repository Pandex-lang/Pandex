#include "../analyzer/lexical.h"
#include <stdio.h>

void test_kwd(char src[]){
	int quantity = scan_kwd(src);
	switch(quantity){
		case RET_KWD:
		puts("ret");
		break;
		case CALL_KWD:
		puts("call");
		break;
		case INC_KWD:
		puts("inc");
		break;
		case DEC_KWD:
		puts("dec");
		break;
		case VAR_KWD:
		puts("var");
		break;
		case IF_KWD:
		puts("if");
		break;
		case ELSE_KWD:
		puts("else");
		break;
		case THEN_KWD:
		puts("then");
		break;
		case WHILE_KWD:
		puts("while");
		break;
		case FOR_KWD:
		puts("for");
	}
}

int main(){

	test_kwd(" inc");
	test_kwd("\tdec");
	test_kwd("\tcall\t");
	test_kwd("var");
	test_kwd("\nif");
	test_kwd(" else ");
	test_kwd("\nthen\n");
	test_kwd("\twhile");
	test_kwd("for\n");
}
