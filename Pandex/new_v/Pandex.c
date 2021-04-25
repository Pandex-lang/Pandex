#include "comment.c"

int main(){
    char str[] = "putc \"Hello , World\"\n";
    char sl[1024];
    char *dest = strstr(str, "main:\n");
    int pos;
    pos = dest - str;
    comment(str);
    char code[1024];
    //printf("%s",code);
    char*token=strtok(str,"\n");
    while(token!=NULL){
        if(token[0]=='p'&&token[1]=='u'&&token[2]=='t')
            switch(token[3]){
                case 'c':
                        printf("%c",token[6]);
                    break;
                case 's':
                    printf("wil Support in later");
                    break;
                default:
                    printf("Undefined");
            }
        if(token[0]=='v'&&token[1]=='a'&&token[2]=='r')
            switch(token[5]){
                case 0x7F:
                    printf("Unsupported");
                    break;
                default:
                    printf("UNSUPPORTED IN THIS VERSION");
            }
        token=strtok(NULL,"\n");
    }
    return 0;
}