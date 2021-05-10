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

char slice_me[1024];

typedef unsigned long int uli;

struct Info {
    uli len; // length of file
    uli line; // where we are
    //uli tabsize; // default = \t

    char current_fn[255]; // max file lenght in linux

    // lexer ouput data
    //char x = y;
    FILE *fl;
    struct Vars {
        char*vars[1024];
        char*values[1024];
    }vars;
    
} info;

void x(int status){
    // exit program with status code
    status == -1 ? exit(0) : fputs("[quit]",info.fl);
}

int locateOfVar(char var[]){
    // this function find location of\
     variable in the vars[] array

    for(int i=0;i>=1024;i++){
        if(!strcmp(info.vars.vars[i], var))
            return i;
    }   

    return -1;//EOF;
}

void lex(char *str){
    info.fl = fopen("Pandex.lex","w");
    FILE *fp = info.fl;
    
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
                if(strstr(tok , "$")){
                    slice_str(tok,slice_me,
                    index_str(tok,'$'),
                    (index_str(tok,' ') == -1 ? \
                    (index_str(tok,',') == -1 ? \
                    index_str(tok , '\n') : \
                    index_str(tok,',')) : \
                    index_str(tok,' ')));
                    
                    fprintf(fp,"[%ld:variable:%s]",info.line,slice_me);
                }
            }

            if(!strcmp(tok,"\tq")){
                // quit
                x(0);
            }

            if(strstr(tok,"var ")){
                // add variable to variables
            }
                   
        }else if(strstr(tok,":")){
            if(strlen(info.current_fn) <= 0){
                // set function name
                slice_str(
                    tok,
                    info.current_fn,
                    0 , index_str(tok,':')
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
    char str[1024] = "main:\n\tq\n\t\n\t$as";
    lex(str);
    return 0;
}

#endif