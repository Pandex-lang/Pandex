#ifndef LEXICAL_H // header guard
#define LEXICAL_H

#ifndef SCANNER_H
#   include "lexical/scanner.h"
#endif

#ifndef SYM_TBL_H
#   include "lexical/sym_tbl.h"
#endif

#ifndef DFA_H
#   include "lexical/recognizer.h"
#endif

enum the_token {
    // tokens
    TILDE=T_TILDE,
    ACUTE , BANG ,
    AT , SHARP ,
    DOLLAR ,
    PERCENT , CARET
    , AND , STAR ,
    LPAREN , RPAREN ,
    MINUS , UNDERSCORE
    , PLUS , EQ ,
    OBRACKET ,
    CBRACKET ,
    OBRACE , CBRACE ,
    OR , BACKSLASH ,
    FORWARDSLASH ,
    COLON , SEMICOLON
    , SINGLECOUTE ,
    DOUBLEQOUTE ,
    QUES , LESSER ,
    GREATER , COMMA
    , DOT // end tokens

	// keywords
    , RET = 51, CALL
    , INC , DEC ,
    VAR , IF , ELSE
    , THEN , FOR ,
    WHILE , /* end keywords */
    
    /* numbers */
    NUM0 = 70 ,
    NUM1 , NUM2
    ,NUM3, NUM4
    ,NUM5, NUM6
    ,NUM7, NUM8
    ,NUM9 /*
    end
    positive
    numbers*/

    /* negative numbers */
    ,
    NNUM0 = 80 ,
    NNUM1 , NNUM2 ,
    NNUM3 , NNUM4 ,
    NNUM5 , NNUM6 ,
    NNUM7 , NNUM8 ,
    NNUM9 ,
    /* end negative
    numbers */
    NEW_LINE = 99
};


struct Tokenizer
{
	enum the_token TOKEN;
	struct Tokenizer *next;
	struct Tokenizer *prev;
};
void swap_tokenizer(int /* token id */ , struct Tokenizer *);
_Bool lex1line_str(char* ,/* struct Symbol_table * ,*/ struct Tokenizer *);

#endif
