#ifndef SYM_TBL_H
#define SYM_TBL_H
// Pandex symbol table
// Method = linked list ( no mixer )
#ifndef _STDBOOL_H
#   include <stdbool.h>
#endif

struct symbol_table
{
    unsigned short int scope;
    char *name;
    char *value;
    size_t addr; // address of variable in memory
    struct symbol_table *next;
};


struct symbol_table *main_app;


bool lookup_symbol(char[]);
bool insert_symbol(char[] , char[] , unsigned short int);

size_t calculateAddressOfVariableInMemory();


typedef struct symbol_table PandexSymbolTablesType; // JFN : Just for fun

#endif
