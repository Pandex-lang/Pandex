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
bool insert_symbol(char name[])
{
    if(lookup_symbol(name) == true)
        return false; // symbol exits
    
    
}