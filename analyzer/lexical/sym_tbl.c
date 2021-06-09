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
