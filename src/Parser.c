#include "./include/Parser.h"

SS_PARSER* init_parser(SS_LEXER* lexer)
{
  SS_PARSER* parser = calloc(1, sizeof(struct SSCRIPT_PARSER_STRUCT));
  parser->lexer = lexer;
  parser-token = lexer_next_token(lexer)
}

SS_TOKEN* parser_eat(SS_PARSER* parser int type)
{
  if(parser->token->type != type)
  {
    printf("[Parser]: Unexpected token: %s, was expecting: %s\n", token_to_str(parser->token), token_type_to_str(type));
    exit(1);
  }
  parser->token = lexer_next_token(parser->lexer);
  return parser->token;
}

SS_AST* parser_parse(SS_PARSER* parser)
{
  return init_ast(AST_NOOP);
}

SS_AST* parser_parse_compound(SS_PARSER* parser)
{
  // SS_AST* compound = init_ast(AST_COMPOUND);
  while(parse->token->type != TK_EOF)
  {
    /* SS_AST* child = */parser_parse(parser);
  }
  return init_ast(AST_NOOP);
}