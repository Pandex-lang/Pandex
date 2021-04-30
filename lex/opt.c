#ifndef OPT_C
#define OPT_C 1
/* Pandex code optimizer 
This file delete unused variables comments & thngs like them 
*/

void comment(char*str){
    // this function delete comments in code //
    int i=0;
    int cmnt_s=0; // short for comment_started
    int len = strlen(str);
    while(i<len){
        if(str[i] == '\n' && cmnt_s){
            cmnt_s=0;
        }else if(str[i] == ';'){
            cmnt_s=1;
        }
        /*cmnt_s=0;
        if(str[i]==';' && !cmnt_s)cmnt_s=1;*/
        if(cmnt_s)str[i]=0x7F;
        i++;
    }
}

#endif