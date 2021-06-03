#include "../analyzer/lexical/scanner.h"

#include <stdbool.h>
#include <stdio.h>

int main(){
	// isNumeric() function
	bool n0 = isNumeric('0');
	bool n1 = isNumeric('1');
	bool n2 = isNumeric('2');
	bool n3 = isNumeric('3');
	bool n4 = isNumeric('4');
	bool n5 = isNumeric('5');
	bool n6 = isNumeric('6');
	bool n7 = isNumeric('7');
	bool n8 = isNumeric('8');
	bool n9 = isNumeric('9');
	bool nn = isNumeric('a');
	bool nnn = isNumeric('z');
	bool nnnn = isNumeric('A');
	bool nnnnn = isNumeric('Z');

	if ( n0 && n1 && n2 && n3 && n4
	&& n5 && n6 && n7 && n8 && n9 )
		puts("isNumeric function check numbers to correctly (YES)");
		
	if ( nn || nnn || nnnn || nnnnn)
		puts("isNumeric function think alpha characters are number (ERROR)");
	// end isNumeric
	
	// isAlpha
	bool a0 = isAlpha('a');
	bool a1 = isAlpha('z');
	bool a2 = isAlpha('A');
	bool a3 = isAlpha('Z');
	bool a4 = isAlpha('s');
	bool a5 = isAlpha('Q');
	bool a6 = isAlpha('b');
	bool a7 = isAlpha('B');
	bool a8 = isAlpha('Y');
	bool a9 = isAlpha('y');
	bool a = isAlpha('0');
	bool aa = isAlpha('9');
	bool aaa = isAlpha('8');
	
	if ( a0 && a1 && a2 && a3 && a4
	&& a5 && a6 && a7 && a8 && a9)
		puts("isAlpha() works correctly (YES)");
		
	if ( a || aa || aaa)
		puts("isAlpha works uncorrect ( ERROR )");
	// end isAlpha
	
	int type;
	type = getCharType('~');
	if ( type == token )
		puts ( "getCharType(tok) works correct (YES)");
	else
		puts("getCharType(tok) works uncorrect (ERROR)");
		
	type = getCharType('0');
	if ( type == number)
		puts("Yes");
	else
		puts("no");

	type = getCharType('9');
	if ( type == number)
		puts("Yes");
	else
		puts("no");

	type = getCharType('5');
	if ( type == number)
		puts("Yes");
	else
		puts("no");
		
	type = getCharType('A');
	if(type != alpha)
		puts("getCharType(alpha) works uncorrec");
		
	puts("testing getCharNum function");
	int num0 = getCharNum('0',false);
	int num1 = getCharNum('1',false);
	int num2 = getCharNum('5',false);
	int num3 = getCharNum('9',false);
}
