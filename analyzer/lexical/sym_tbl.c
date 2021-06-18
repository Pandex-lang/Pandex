// implementation of sym_tbl.h
#ifndef SYM_TBL_H
#    include "sym_tbl.h"
#endif

#ifndef _STDBOOL_H
#    include <stdbool.h>
#endif

#ifndef _STRING_H
#    include <string.h>
#endif

#ifndef _STDLIB_H
#    include <stdlib.h>
#endif

bool lookup_by_name(char*name , 
struct Symbol_table *table)
{
	struct Symbol_table *copied
		= table; // copy second argument into copied
	

	/* colorize the source */
	
	do
		if (strcmp (copied->name , name) == 0)	
			return true;
	while(/* Assign */ (copied = (*copied).next) /* end */);

	return false;
}

bool check_scope(struct Symbol_table *ptr , 
unsigned short int scope){
	if(ptr->scope == scope)
		return true;

	return false;
}

bool insert_table(
struct Symbol_table * MAIN ,
struct Symbol_table insert_it){

	MAIN->next = &insert_it;

	if(MAIN->next); // segment fault if MAIN->next is not exits
	return true;
}

struct Symbol_table make_table(char*name,char*value){
	struct Symbol_table *TABLE = (struct Symbol_table *) malloc(sizeof(struct Symbol_table));

	TABLE->name = name;
	TABLE->value = value;
	TABLE->scope = 0;
	TABLE->addr = calc_addr();

	return *TABLE;
}

unsigned long long int calc_addr(){
	static unsigned long long int 
	addr = 999; // a thosound is \
	primary address for each variable

	return ++addr;
}
