// implementation of sym_tbl.h
#ifndef _STDBOOL_H
#   include <stdbool.h>
#endif

#ifndef _STRING_H
#   include <string.h>
#endif

#ifndef _STDLIB_H
#   include <stdlib.h>
#endif

#ifndef SYM_TBL_H
#   include "sym_tbl.h"
#endif

bool lookup_symbol(char name[])
{
    struct symbol_table *ptr = main_app;
    do
        if(strcmp(ptr->name,name) == 0)
            return true;
    while( (ptr = ptr->next) != NULL);

    return false;
}

// The insert method return true if variable insered correctly
bool insert_symbol
(char name[] , char value[]
unsigned short int scope )
{
    if(lookup_symbol(name) == true)
        return false; // symbol exits
        

    struct *ptr = main_app;
    
    // set position of ptr to last 
    while ( ( ptr = ptr->next ) != NULL);
    
    ptr->scope = scope;
    ptr->name = name;
    ptr->value = value;
    ptr->addr = calculateAddressOfVariableInMemory(); // \
    I name this method like C# programmers . Yes ? :-)
    
    return 0;


}

size_t
calculateAddressOfVariableInMemory()
{
	static unsigned long int address = 100; // for lexical \
	usage . scanner return an id ( to integer/number ) and \
	lexer understand that what token is here . but scanner \
	cannot return variables so sym_tbl is main architecture \
	for variable
	
	return address++;
		
}
