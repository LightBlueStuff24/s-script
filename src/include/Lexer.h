#ifndef __SS_LEXER_H__
#define __SS_LEXER_H__
#include "Token.h"
#include <stdio.h>

typedef struct LEXER_SSCRIPT_STRUCT
{
  char* src;
  size_t src_size;
  char c;
  unsigned int idx;
} SS_LEXER;

SS_LEXER* init_lexer(char* src); // init

void lexer_adv(SS_LEXER* lexer); // advance

char lexer_peek(SS_LEXER* lexer, int offset);

void lexer_skip_whitespace(SS_LEXER* lexer);

SS_TOKEN* lexer_parse_id(SS_LEXER* lexer);

SS_TOKEN* lexer_parse_number(SS_LEXER* lexer);

SS_TOKEN* lexer_adv_with(SS_LEXER* lexer, SS_TOKEN* token);

SS_TOKEN* lexer_adv_current(SS_LEXER* lexer, int type);

SS_TOKEN* lexer_next_token(SS_LEXER* lexer); // nextTK


#endif // __SS_LEXER_H__