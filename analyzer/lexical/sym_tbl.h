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
	unsigned int addr;
	struct Symbol_table *next;
};


bool lookup_by_name(char*
, struct Symbol_table *);
/*
bool inseeffeert(){return false;} // insert() insert a symbol into , \
insert() returns the true if the insert is successful*/
#endif
