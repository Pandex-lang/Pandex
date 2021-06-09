#include "../analyzer/lexical/sym_tbl.h"
#include <stdbool.h>
int main(){
	struct Symbol_table f = {0,"nm","val",1404};
	struct Symbol_table *ptr = &f;
	struct Symbol_table tbl = {0,"name","value",1000 , ptr};
	bool r = lookup_by_name("nm",&tbl);
	if(r)
		puts("Hello");

	return 0;
	
}
