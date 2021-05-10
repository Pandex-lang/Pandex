#ifndef IO_C
#define IO_C 1
/* Pandex std file io ( standard file input/output )  */
#ifndef _STDIO_H
#include <stdio.h>
#endif

#ifndef _STDLIB_H
#include <stdlib.h>
#endif

// declurations
void fileToText(char[],char[]);
void fileLen(char[]);

struct File {
    FILE *fp;
    unsigned long int len;
    //char source[len];

}file;

void fileToText(char name[] , char slice[]){
    file.fp = fopen(name,"r");

    // fileLen(name) \
    You Should Execute the fileLen function \
    before running this function for set the \
    file.len variable

    fread(slice, file.len , 1, file.fp);
    fclose(file.fp);
}

void fileLen(char name[]){
    FILE *fp = fopen(name,"r");
    fseek(fp , 0 , 2); // #def seek_end 2
    file.len = ftell(fp);
    fclose(fp);
}

/*
int main(){
    fileLen("file.txt");
    char src[file.len];
    fileToText("file.txt",src);
    printf("%s",src);
    return 0;
}*/

#endif