// declurations of sym_tbl.c
#ifndef SYM_TBL_H // header guard
#define SYM_TBL_H

#ifndef _STDBOOL_h
#    include <stdbool.h>
#endif

struct Symbol_table
{
	unsigned short int scope;
	char *name;
	char *value;
	unsigned long long int addr;
	struct Symbol_table *next;
};


bool lookup_by_name(char*
, struct Symbol_table *);

bool check_scope
(struct Symbol_table *
, unsigned short int); // \
check is variable is in same scope


bool insert_table(
struct Symbol_table * /* MAIN */ ,
struct Symbol_table /* insert_it*/
);

struct Symbol_table make_table(char*,char*);

// calculate address of variable \
for symbol table
unsigned long long int
calc_addr();

#endif
