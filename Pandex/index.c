#include <stdio.h>
#include <string.h>

char numToAlph(int num){
    switch(num){
        case 1:return 'a';
        case 2:return 'b';
        case 3:return 'c';
        case 4:return 'd';
        case 5:return 'e';
        case 6:return 'f';
        case 7:return 'g';
        case 8:return 'h';
        case 9:return 'i';
        case 10:return 'j';
        case 11:return 'k';
        case 12:return 'l';
        case 13:return 'm';
        case 14:return 'n';
        case 15:return 'o';
        case 16:return 'p';
        case 17:return 'q';
        case 18:return 'r';
        case 19:return 's';
        case 20:return 't';
        case 21:return 'u';
        case 22:return 'v';
        case 23:return 'w';
        case 24:return 'x';
        case 25:return 'y';
        case 26:return 'z';
    }
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
    
    char cmds[] = ".120\nintoc";
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
        }
        /* end */
        token = strtok(NULL, "\n");
    }
    return 0;
}
