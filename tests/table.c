#include "../analyzer/lexical/sym_tbl.h"


#include <stdbool.h>
#include <stdio.h>

int main(){
	// no check_scope function test exits here

	// test make_table function
	struct Symbol_table base = make_table("var" , "Hello , World");

	struct Symbol_table after = make_table("var2" , "Hello , world too");

	// test insert function

	insert_table(&base /* base is main table */ ,
	after /* after insert into main(base) */);

	// test lookup_by_name function
	bool r = lookup_by_name("var2",&base);

	if(r)
		puts("Yes :)");

	return 0;
	
}
