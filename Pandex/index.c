#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void al_error(char*error,char *type,char *in){
    printf("in line %s : an error from type %s created with contrnt \n %s",in,type,error);
}

void slice_str(const char * str, char * buffer, int start, int end){
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

char numToAlph(int num){
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

int main(int argc , char *argv[]){
    /* processing file */
    if(argc!=2){
        printf("An argument is needed as command");
        return 0;
    }

    //memcpy(revS,tesr,50);
    /* end */ 
    char *vars[9],*values[9];
    char *funcs[9],*codes[9];
    int v_i = 0; // variable iterator
    int f_i = 0; // function iterator

    char *token = strtok(argv[1], "\n");
    while (token != NULL)
    {   fn: 
        // this label used for translate function to code
        /* proc */ 
        if(streq(token,"intoc")){
            printf("Hello , World!");
        }
        else if (token[0] == '.'){
            if(token[0] && token[1] && token[2] && token[3] && !token[4]){
                int one_number = token[1]-'0';
                int two_number = token[2]-'0';
                int three_number = token[3]-'0';
                int characterAsciiCode = (one_number+(two_number+three_number));
                if(characterAsciiCode <= 26){
                    printf("%c" , numToAlph(characterAsciiCode));
                }else{
                    printf("\n");
                }
            }
        }else if(isBe(token,'%') && token[0] != '%'){
            int where = whereIs(token,'%');//whereIs(token,'%');
            /* add name of variable is the vars[] array */
            char sliced_0[1024];
            slice_str(token,sliced_0,0,(where-1));
            vars[v_i] = sliced_0;
            /* add value of variable is values[] array */
            char sliced_1[1024];
            slice_str(token,sliced_1,(where+2),strlen(token));
            values[v_i] = sliced_1;
            v_i+=1;  
            if(v_i == 10){
                printf("Out of 9 variable in code");
                return 1;
            }
            remove(sliced_0);
            remove(sliced_1);
        }
        else if(token[0] == '%'){
            /* here used for when user use %1 or call a variable Pandex can answer */
            printf("%s",values[(token[2]-'0')]);
        }else if (token[0] == '=' && token[1] == '>'){
            char sliced__0[1024];
            slice_str(token,sliced__0,2,(whereIs(token,',')-1));
            char sliced__1[1024*1024];
            slice_str(token,sliced__1,whereIs(token,',')+1,whereIs(token,'\n'));
            funcs[f_i] = sliced__0;
            codes[f_i] = sliced__1;
            f_i+=1;
            if(f_i == 10){
                printf("Out of 9 function is code is be !");
                return 1;
            }
            remove(sliced__0);
            remove(sliced__1);
        }else if(token[0] == '=' && token[1] == '<'){
            // calling the functions 
            char sliced___0[1024];
            int i=0;
            while(!i<=9){
                token="intoc";
            }
        }
        /* end */
        token = strtok(NULL, "\n");
    }
    return 0;
}
