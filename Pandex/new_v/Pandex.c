#include "comment.c"

int main(){
    char str[] = "main:\n\tputs \"Hello , World\"";
    char sl[1024];
    char *dest = strstr(str, "main:\n");
    int pos;
    pos = dest - str;
    comment(str);
    char code[1024];
    slice_str(str,code,7,strlen(str));
    printf("%s",code);
    char*token=strtok(code,"\n");
    while((token=strtok(NULL,"\n"))!=NULL){
        if(strstr(token,"puts")){
            slice_str(token,sl,3,strlen(token));
            printf("%s",sl);
        }
    }
    return 0;
}