#include "str.c"
/* this function get the file name 
and convert file to string or array 
of characters like following file
code.code : "The Codes Are Here"
char str[];
fileToText("code.code",str);
str = "The Codes Are Here" */
void fileToText(char *name , char *slice){
    FILE *fp = fopen(name,"r");
    fseek(fp , 0 , SEEK_END);
    int len = ftell(fp);
    fclose(fp);
    fp = fopen(name,"r");
    fgets(slice , len , fp);
}
