#ifndef SCANNER_H
#define SCANNER_H

#ifndef _STDBOOL_H
#   include <stdbool.h>
#endif

#ifndef _STDDEF_H
#   include <stddef.h>
#endif

#define alpha 0 // if character is alpha like a:b:c:d
#define number 1 // if character is number 1:2:3
#define token 2 // if character is token \
( e.g ~@#$%*()+_=-`'":{[]}")

#define T_TILDE 10 // ~
#define T_ACUTE 11 // `
#define T_BANG 12 // !
#define T_AT 13 // @
#define T_SHARP 14 // #
#define T_DOLLAR 15 // $
#define T_PERCENT 16 // %
#define T_CARET 17 // ^
#define T_AND 18 // &
#define T_STAR 19 // *
#define T_LPAREN 20 // ( LPAREN = LEFT PARANTHES
#define T_RPAREN 21 // ) RPAREN = RIGHT PARANTHES
#define T_MINUS 22 // - (HYPHEN . MINUS . DASH)
#define T_UNDERSCORE 23 // _
#define T_PLUS 24 // +
#define T_EQ 25 // =
#define T_OBRACKET 26 // [ OBRACKET = OPEN BRACKET
#define T_CBRACKET 27 // ] CBRACKET = CLOSE BRACKET
#define T_OBRACE 28 // { OBRACE = OPEN BRACE
#define T_CBRACE 29 // } CBRACE = CLOSE BRACE
#define T_OR 30 // |
#define T_BACKSLASH 31 // \ back slash
#define T_FORWARDSLASH 32 // / forward slash
#define T_COLON 33 // :
#define T_SEMICOLON 34 // ;
#define T_SINGLECOUTE 35 // ' SINGLE COUTE
#define T_DOUBLEQOUTE 36 // " DOUBLE COUTE
#define T_QUES 37 // ?
#define T_LESSER 38 // <
#define T_GREATER 39 // >
#define T_COMMA 40 // ,
#define T_DOT 41 // .

// keywords
#define RET_KWD 51 // ret kwds
#define CALL_KWD 52
#define INC_KWD 53
#define DEC_KWD 54
#define VAR_KWD 55
#define IF_KWD 56
#define ELSE_KWD 57
#define THEN_KWD 58
#define FOR_KWD 59
#define WHILE_KWD 60

// number
// +
#define NUM_0 70 // 0
#define NUM_1 71 // 1
#define NUM_2 72 // 2
#define NUM_3 73 // 3
#define NUM_4 74 // 4
#define NUM_5 75 // 5
#define NUM_6 76 // 6
#define NUM_7 77 // 7
#define NUM_8 78 // 8
#define NUM_9 79 // 9
// -
#define NNUM_0 80
#define NNUM_1 81
#define NNUM_2 82
#define NNUM_3 83
#define NNUM_4 84
#define NNUM_5 85
#define NNUM_6 86
#define NNUM_7 87
#define NNUM_8 88
#define NNUM_9 89

bool isAlpha(const char); // check if ch is in alphabet
bool isNumeric(const char); // check if ch is a number

int getCharTok(const char); // get the char token id \
( e.g if ch=='~' return T_TILDE=10)
int getCharType(const char); // check if is alpha , numeric or token
int getCharNum(const char , const bool isNegative);

int _scan(const char);

int scan(const char);

int scan_kwd(const char[]);

#endif
