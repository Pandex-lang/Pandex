#ifndef SYM_TBL_H
#define SYM_TBL_H
// Pandex symbol table
// Method = linked list ( no mixer )
#ifndef _STDBOOL_H
#   include <stdbool.h>
#endif


char**mem;

struct symbol_table
{
    unsigned short int scope;
    char *name;
    char *value;
    int addr; // address of variable in memory
    struct symbol_table *next;
};


struct symbol_table *first;
struct symbol_table *last;
struct symbol_table *main_app;


bool lookup_symbol(char[]);
bool insert_symbol();

#endif