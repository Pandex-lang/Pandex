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

#ifndef _STRING_H
#   include <string.h>
#endif

bool isAlpha(const char ch)
{
    if(ch >= 48 && ch <= 57)
        return false;

    if ((ch >= 97 && ch <= 122) ||
        (ch >= 65 && ch <= 90) ){
            return true;
        }

    return false;
}

bool isNumeric(const char ch)
{
    if( (ch >= 97 && ch <= 122) ||
        ( ch >= 65 && ch <= 90)){
            return false;
        }
    if(ch >= 48 && ch <= 57)
        return true;

    return false;
}

int getCharTok(const char ch)
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
            return -1; // EOF (End-Of-File)
        }
    }
    return EOF;
}

int getCharNum(const char ch , const bool isNegative){
    switch(ch){
        case '0':
            if(isNegative)
                return NNUM_0;
            else
                return NUM_0;

        case '1':
            if(isNegative)
                return NNUM_1;
            else
                return NUM_1;

        case '2':
            if(isNegative)
                return NNUM_2;
            else
                return NUM_2;

        case '3':
            if(isNegative)
                return NNUM_3;
            else
                return NUM_3;

        case '4':
            if(isNegative)
                return NNUM_4;
            else
                return NUM_4;

        case '5':
            if(isNegative)
                return NNUM_5;
            else
                return NUM_5;
  
        case '6':
            if(isNegative)
                return NNUM_6;
            else
                return NUM_6;

        case '7':
            if(isNegative)
                return NNUM_7;
            else
                return NUM_7;

        case '8':
            if(isNegative)
                return NNUM_8;
            else
                return NUM_8;

        case '9':
            if(isNegative)
                return NNUM_9;
            else
                return NUM_9;

        default: return -1; // EOF

    }
}

int getCharType(const char ch)
{
    if(isAlpha(ch))
        return alpha;
    else if(isNumeric(ch))
        return number;
    else
        return token;
}

/*
@_scan:(char):int
It's scanner main function
that read the source and
scan source and return the
id of token/kwd/var .
*/
int _scan(const char src)
{
    //
    size_t type = getCharType(src); // getCharType return the type to integer : \
    alpha=0 , number=1 , token2

    if(type == token)
        return getCharTok(src);
    if (type == number )
    	return getCharNum(src , false);
    if (type == alpha )
    	return alpha;

}

/*
@scan:(char):int
the scan function
scan the source and
help to `analyer/lexical`
to create a token lists
But What's difference between
_sacn and scan(this) function ?
The _scan function used in scan
but _scan cannot lex alpha but can
lex numbers and tokens So the scan
function available lexing alpha and
use of _scan for lexing numbers and 
tokens 
*/

int scan(const char source){
	size_t result = _scan(source);
	if ( result == alpha){
		return source;

	}else
		return result; // may be hard to understand ? :/ or :\
		which of them :)
}


/*
this function 
return keywords
id | lex keyword.
this function when
detect first keyword
in source , return 
the keyword so function
will stopped and do not
return next keywords
*/
int scan_kwd(const char source[]){
	size_t length = strlen(source);
	 
	char *ptr = malloc(length); // new string
	int ptr_cur_pos = 0; // position of new string
	for(size_t i = 0; i < length; i++)
	{
		if ( source[i] != ' ')
			ptr[ptr_cur_pos++] = source[i];
	}
	
	ptr[ptr_cur_pos++] ='\0';

		// delete whitespaces

		/*
		if ( strcmp (
			tok ,
			"keyword" ,
			length
			)
		)
		
		check is tok is equal to kywords and
		pass the length of keyword to latest
		strncmp argument
		*/
		
	if ( strncmp (ptr , "ret" , 3) == 0)
		return RET_KWD;
		
	if ( strncmp (ptr , "call" , 4) == 0)
		return CALL_KWD;

	if ( strncmp (ptr , "inc" , 3) == 0)
		return INC_KWD;

	if ( strncmp (ptr , "dec" , 3) == 0)
		return DEC_KWD;

	if ( strncmp (ptr , "var" , 3) == 0)
		return VAR_KWD;

	if ( strncmp (ptr , "if" , 2) == 0)
		return IF_KWD;
			
	if ( strncmp (ptr , "else" , 4) == 0)
		return ELSE_KWD;

	if ( strncmp (ptr , "then" , 4) == 0)
		return THEN_KWD;
			
	if ( strncmp (ptr , "for" , 3) == 0)
		return FOR_KWD;
			
	if ( strncmp (ptr , "while" , 5) == 0)
		return WHILE_KWD;
			
	return EOF; // if was not keyword
}
