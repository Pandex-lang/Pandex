// C
#ifndef SCANNER_H
#   include "lexical/scanner.h"
#endif

#ifndef SYM_TBL_H
#   include "lexical/sym_tbl.h"
#endif

#ifndef DFA_H
#   include "lexical/recognizer.h"
#endif

enum operand {
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

    ,

};


struct Tokenizer
{

    struct Tokenizer *next;
    struct Tokenizer *prev;
};
