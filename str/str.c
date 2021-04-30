/* this file have all of string function that don't exits
int string.h header and is required for processing in the
strings like slicing */
#ifndef STR_C
#define STR_C 1

#ifndef _STRING_H
#include <string.h>
#endif

void slice_str(char*str,char*slice,int start,int end){
    /* this function is like slice method in javascript
    or str[start:end] in python and get a string named str
    and start and end next from move to slice value of str
    from start to end */
    int j=0;
    for(int i=start;i<end;i++){
        slice[j++] = str[i];
    }
    slice[j] = 0;
}

int index_str(char *str , char chr){
    /* this function return location of a character in integer
    value from a string like following that return location 
    str:"Hello , World" : location of , 6 :*/
    for(int i=0;i<strlen(str);i++){
        if(str[i] == chr){
            return i;
        }
    }
    return -1;
}

int streq(char *str , char *isEq){
    /* This function check if two string is equal */
    unsigned short  int length = strlen(str); // length of the (*str) string 
    if(length==strlen(isEq)){ // if length of two string is equal run codes else return 1;
        for(int i=0;i<length;i++){ // translate string to char array
            if(str[i] != isEq[i]){ // if character of strings is not equal return FALSE // or 0
                return 0;
            }
        }
        return 1; 
    }else{ 
        return 0;
    }
}

#endif