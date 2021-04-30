#ifndef TOKEN_C
#define TOKEN_C 1
/* 
The Pandex programming language tokenizer 

this file is a component for lexer ( lex.c )
*/

    // token[0] = ':'; is equal with \
    int colon = 0; and it's better
char Token[7] = 
{
        ':',
        '[',
        ']',
        '{',
        '}',
        ',',
        '~'
};

#endif

// sizeof(tokens)/sizeof(tokens[0]);