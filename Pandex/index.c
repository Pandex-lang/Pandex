#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void slice_str(const char * str, char * buffer, int start, int end)
{
    int j = 0;
    for ( int i = start; i <= end; ++i ) {
        buffer[j++] = str[i];
    }
    buffer[j] = 0;
}

int whereIs(char *string , char where){
    for(int i=0;i<strlen(string);i++){
        if(string[i] == where){
            return i;
        }
    }
}

char numToAlph(int num) {
    return (num >= 1 && num <= 26) ? (char)(96 + num) : ' ';
}

int isBe(char *str , char delim){
    /* if str contain delim */
    for(int i=0;i<strlen(str);i++){
        if(str[i] == delim){
            return 1;
        }
    }
    return 0;
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

int getFileSize(FILE *file){
    fseek(file, 0L, SEEK_END);
    return (ftell(file));
}

int main(){
    /* processing file */
    /*FILE *fp = fopen(argv[1],"r");
    char cmds[1024];
    fgets(cmds,getFileSize(fp),fp);
    /* end */ 
    char **vars;
    char **values;
    int v_i = 0; // variable iterator

    char cmds[] = ".120\nintoc\n";
    char *token = strtok(cmds, "\n");
    while (token != NULL)
    {
        /* proc */ 
        if(streq(token,"intoc")){
            printf("Hello , World!");
        }
        else if (token[0] == '.'){
            int one_number = token[1]-'0';
            int two_number = token[2]-'0';
            int three_number = token[3]-'0';
            int characterAsciiCode = (one_number+(two_number+three_number));
            printf("%c\n" , numToAlph(characterAsciiCode));
        }else if( whereIs(token,'%') != NULL){
            int where = whereIs(token,'%');
            /* add name of variable is the vars[] array */
            char sliced[1024];
            slice_str(token,sliced,0,where);
            vars[v_i] = sliced;
            /* add value of variable is values[] array */
            sliced = "\0";
            slice_str(token,sliced,where,strlen(token));
            values[v_i] = sliced;

            v_i+=1;  
        }
        // end
        token = strtok(NULL, "\n");
    }
    return 0;
}
