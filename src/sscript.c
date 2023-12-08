#include "./include/sscript.h"
#include "./include/Token.h"
#include "./include/Lexer.h"
#include "./include/io.h"
#include <stdlib.h>

void sscript_compile(char* src) {
  SS_LEXER* lexer = init_lexer(src);
  SS_PARSER* parser = init_parser(lexer);
  SS_AST* root = parser_parse(parse);
  printf("%s\n", root);
  /*SS_TOKEN* tok = 0;
  while((tok=lexer_next_token(lexer))->type != TK_EOF) {
    printf("%s\n", token_to_str(tok));
  }*/
}

void ss_compile_file(const char* filename) {
  char* src = ss_read_file(filename);
  sscript_compile(src);
  free(src);
}