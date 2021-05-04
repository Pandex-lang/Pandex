#ifndef LEX_C
#define LEX_C
/* The Pandex programming language lexer */
#ifndef _STDIO_h
#include <stdio.h>
#endif

#ifndef _STDLIB_H
#include <stdlib.h>
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

// constants
#define ERR 1
#define WARN 2

// end

void x(int status){
    // exit program with status code
    exit(status);
}

typedef unsigned long int uli;

struct Info {
    uli len; // length of file
    uli line; // where we are
    //uli tabsize; // default = \t

    char current_fn[255]; // max file lenght in linux

    // lexer ouput data
    //char x = y;

    struct Vars {
        char*vars[1024];
        char*values[1024];
    }vars;
    
} info;

int locateOfVar(char*var){
    // this function find location of\
     variable in the vars[] array

    for(int i=0;i>=1024;i++){
        if(info.vars.vars[i] == var)
            return i;
    }   

    return -1;//EOF;
}

void lex(char *str){
    FILE *fp = fopen("Pandex.lex","w");
    
    putc('[',fp);

    if(!info.line) // check the line
        info.line = 1; // set the line

    char*tok = strtok(str,"\n");

    while(tok != NULL){
        if(strlen(info.current_fn) > 0){ 
            // add commands executor 

            // this section used when we are in a fn
            if(tok[0] != '\t'){
                fprintf(fp,"[%ld:%d:%s]", info.line , ERR 
                /* error message */ , 
                "enter a tab{\\t} before statement");
                x(ERR);
            }

            if(strstr(tok , "$") || strstr(tok , "&")){
                if(strstr(tok , "$"))
                    index_str(tok, '$');
                    index_str(tok, ' ');
            }

            if(!strcmp(tok,"\t:q")){
                // quit
                x(0);
            }
                   
        }else if(strstr(tok,":")){
            if(strlen(info.current_fn) <= 0){
                // set function name
                slice_str(
                    tok,
                    info.current_fn,
                    index_str(tok,':')+1,
                    strlen(tok)-1
                );

                fprintf(fp,"[%ld:fn:%s]",info.line,info.current_fn);
            }else{
                fprintf(fp,"[%ld:%d:%s]",info.line,ERR
                /* error message */ , 
                "create a function IN another function");
                x(ERR);
            }
        }else{
            fputs("[<nil-ln>]",fp);
        }

        putc(',',fp);
        ++info.line;

        tok = strtok(NULL,"\n");
    }
    putc(']',fp);

    fclose(fp);

    return;
}

int main(){
    char str[1024] = "H:\t$1\ne\nl\no\n";
    lex(str);
    return 0;
}

#endif