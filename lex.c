#ifndef LEX_C
#define LEX_C
/* The Pandex programming language lexer */
#ifndef _STDIO_h
#include <stdio.h>
#endif

#ifndef _STRING_H
#include <string.h>
#endif

#ifndef OPT_C
#include "lex/opt.c"
#endif

#ifndef TOKEN_C
#include "lex/token.c"
#endif

#ifndef STR_C
#include "str/str.c"
#endif

struct Info {
    unsigned long int len; // length of file
    unsigned long int line; // where we are
    int tabsize; // codes must be wihch location (following)
    /*
    main:
        putc 'a'
    (tabsize=4)
    main:
      putc 'a'
    (tabsize=2)
    */
    char current_fn[1024];

    // lexer ouput data
    char filename; // name of file that lexer output will wrute there
    
} info;

void lex(char *str){
    char*tok = strtok(str,"\n");
    if(!info.line) // check the line
        info.line = 0; // set the line

    while(tok != NULL){
        if(strstr(tok,":")){
            if(!file.current_fn){
                // set function name
                slice_str(
                    token,
                    file.current_fn,
                    index_str(token,':'),
                    index_str(token,'\n')
                );
            }
            // program starts from there
        }
        ++info.line;
        tok = strtok(NULL,"\n");
    }
}

int main(){
    char str[1024] = "H\ne\nl\no\n";
    lex(str);
    return 0;
}

#endif