// implemention of declurations in `scanner.h` file

#ifndef SCANNER_H
#   include "scanner.h"
#endif

#ifndef _STDBOOL_H
#   include <stdbool.h>
#endif

#ifndef _STDLIB_H
#   include <stdlib.h>
#endif

#ifndef _STDIO_H
#   include <stdio.h>
#endif

bool isAlpha(char ch)
{
    if(ch >= 48 && ch <= 57)
        return false;
    
    if( (ch >= 97 && ch <= 122) ||
        (ch >= 65 && ch <= 90) ){
            return true;
        }

    return false;
}

bool isNumeric(char ch)
{
    if( (ch >= 97 && ch <= 122) ||
        ( ch >= 65 && ch <= 90)){
            return false;
        }
    if(ch >= 48 && ch <= 57)
        return true;

    return false;
}

int getCharTok(char ch)
{
    if(getCharType(ch) == token){
        switch(ch){
        // NOTE : cases don't needs break because when a \
        case executed return a thing that means end of function

        case '~':
            return T_TILDE;
        case '`':
            return T_ACUTE;
        case '!':
            return T_BANG;
        case '@':
            return T_AT;
        case '#':
            return T_SHARP;
        case '$':
            return T_DOLLAR;
        case '%':
            return T_PERCENT;
        case '^':
            return T_CARET;
        case '&':
            return T_AND;
        case '*':
            return T_STAR;
        case '(':
            return T_LPAREN;
        case ')':
            return T_RPAREN;
        case '-':
            return T_MINUS;
        case '_':
            return T_UNDERSCORE;
        case '+':
            return T_PLUS;
        case '=':
            return T_EQ;
        case '[':
            return T_OBRACKET;
        case ']':
            return T_CBRACKET;
        case '{':
            return T_OBRACE;
        case '}':
            return T_CBRACE;
        case '|':
            return T_OR;
        case '\\':
            return T_BACKSLASH;
        case '/':
            return T_FORWARDSLASH;
        case ':':
            return T_COLON;
        case ';':
            return T_SEMICOLON;
        case '\'':
            return T_SINGLECOUTE;
        case '"':
            return T_DOUBLEQOUTE;
        case '?':
            return T_QUES;
        case '<':
            return T_LESSER;
        case '>':
            return T_GREATER;
        case ',':
            return T_COMMA;
        case '.':
            return T_DOT;

        default:
            return -1; // EOF ( End-Of-File)
        }
    }
}

int getCharType(char ch)
{
    if(isAlpha(ch))
        return alpha;
    else if(isNumeric(ch))
        return number;
    else
        return token;
}

/*
@scan:(char[]|int)
It's scanner main function
that read the source and
scan source and return the
id of token/kwd/var . it's
start reading from cur to
first return .
*/
int scan
(const char src[] ,
const int cur){
    ///
    

}