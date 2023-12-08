#ifndef __SSCRIPT_PARSER_H__
#define __SSCRIPT_PARSER_H__
#include "Lexer.h"
#include "AST.h"
#include "Token.h"

typedef struct SSCRIPT_PARSER_STRUCT
{
  SS_LEXER* lexer;
  SS_TOKEN* token;
} SS_PARSER;

SS_PARSER* init_parser(SS_LEXER* lexer);

SS_TOKEN* parser_eat(SS_PARSER* parser, int type);

SS_AST* parser_parse(SS_PARSER* parser);

SS_AST* parse_compound(SS_PARSER* parser);


#endif // __SSCRIPT_PARSER_H__