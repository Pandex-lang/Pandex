Pandex development very principled so you should understand following things and more things
* lexical analyzer
* syntax analyzer
* semantic analyzer
* scanner
* symbol table
* tokens
* QuI when Q = {1 ,2} and I = {a ,b}

this language developed of the اصول طراحی کامپایلر ها from the جعفر پور امینی but you can learn the chapters in the [tutorialspoint.com course](https://www.tutorialspoint.com/compiler_design/index.htm)

# Structur

* The `conf.h` contain configurations
* The `analyzer` directory contain lexical , syntax and semantic analyzers
* The `analyzer/lexical` contain lexcial analyzer component ( e.g `scanner`)
* The `analyzer/syntax` contain syntax analyzer component
* The `analyzer/semantic` contain semantic analyzer components

# Part I|1 Scanner
The scanner check the source and read one by one of source characters and return the characters one by one 

*example*

```bash
for $times
```
The scanner returns
``` alpha(f)-alpha(o)-alpha(r)-whitespace-dollar_tok($)-alpha(t)-alpha(i)-alpha (m)-alpha(e)-alpha(s)-whitespace```
**not it's an example only**

The `scanner.c` file contain the `scanner.h` declurations that is following list
* Tokens type and etc
```c
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
#define T_SEMICOLON 34
#define T_SINGLECOUTE 35 // ' SINGLE COUTE
#define T_DOUBLEQOUTE 36 // " DOUBLE COUTE
#define T_QUES 37 // ?
#define T_LESSER 38 // <
#define T_GREATER 39 // >
#define T_COMMA 40 // ,
#define T_DOT 41 // .
```

```c
* _Bool isAlpha(char); // check if ch is in alphabet
* _Bool isNumeric(char); // check if ch is a number
* int getCharTok(char); // get the char token id ( e.g if ch=='~' return T_TILDE=10)
* int getCharType(char); // check if is alpha , numeric or token
```

`scanner` headers used in determinstic finite automaton

# Symbol table
* In `Analyzer directoy`

**Location: [lexical/sym_tbl(.h|.c)](analyzer/lexical/sym_tbl.h)**



The Symbol table hold variable `name`,`address` and `scope` becuase identfiers contain more than one character but lexer retura one token only for an identifier and other things , so symbol table contain identifiers becaus identifiers rel is `< 1`-`1` or `more than one` to `one`

Please more search abuot symbol table


# DFA ( Deterministic Finte Automaon)