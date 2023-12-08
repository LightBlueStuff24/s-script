#include "./include/Lexer.h"
#include "./include/macros.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

SS_LEXER* init_lexer(char* src) {
  SS_LEXER* ss_lexer = calloc(1, sizeof(struct LEXER_SSCRIPT_STRUCT));
  ss_lexer->src = src;
  ss_lexer->src_size = strlen(src);
  ss_lexer->idx = 0;
  ss_lexer->c = ss_lexer->src[ss_lexer->idx];
  return ss_lexer;
}

void lexer_adv(SS_LEXER* lexer) {
  if(lexer->idx < lexer->src_size && lexer->c != '\0') {
    lexer->idx += 1;
    lexer->c = lexer->src[lexer->idx];
  }
}

SS_TOKEN* lexer_adv_current(SS_LEXER* lexer, int type) {
  char* value = calloc(1, sizeof(char));
  value[0] = lexer->c;
  value[1] = '\0';
  SS_TOKEN* token = init_token(value, type);
  lexer_adv(lexer);
  return token;
}

char lexer_peek(SS_LEXER* lexer, int offset) {
  return lexer->src[lexer->idx + offset];
}

SS_TOKEN* lexer_adv_with(SS_LEXER* lexer, SS_TOKEN* token) {
  lexer_adv(lexer);
  return token;
}

void lexer_skip_whitespace(SS_LEXER* lexer) {
  while(lexer->c == 13 || lexer->c == 10 || lexer->c == ' ' || lexer->c == '\t') {
    lexer_adv(lexer);
  }
}

SS_TOKEN* lexer_parse_id(SS_LEXER* lexer) {
  char* value = calloc(1, sizeof(char));
  while(isalpha(lexer->c) || anyofchar(lexer->c, "_&$")) {
    value = realloc(value, (strlen(value) + 2) * sizeof(char));
    strcat(value, (char[]) {
      lexer->c, 0
    });
    lexer_adv(lexer);
  }
  //if(KEYWORDS) {}
  return init_token(value, TK_IDENTIFIER);
}

SS_TOKEN* lexer_parse_number(SS_LEXER* lexer) {
  char* value = calloc(1, sizeof(char));
  while(isdigit(lexer->c)) {
    value = realloc(value, (strlen(value) + 2) * sizeof(char));
    strcat(value, (char[]) {lexer->c});
    lexer_adv(lexer);
  }
  return init_token(value, TK_NUMERIC);
}

SS_TOKEN* lexer_next_token(SS_LEXER* lexer) {
  while(lexer->c != '\0') {
    lexer_skip_whitespace(lexer);
    if(isalpha(lexer->c) || anyofchar(lexer->c, "_&$")) {
      return lexer_adv_with(lexer, lexer_parse_id(lexer));
    }
    if(isdigit(lexer->c)) {
      return lexer_adv_with(lexer, lexer_parse_number(lexer));
    }
    switch(lexer->c) {
      case '=': {
        if(lexer_peek(lexer, 1) == '>') lexer_adv(lexer); return lexer_adv_with(lexer, init_token("=>", TK_FUNC_ARROW));
        if(lexer_peek(lexer, 1) == '+') lexer_adv(lexer); return lexer_adv_with(lexer, init_token("=+", TK_EQUAL_PLUS)); 
        if(lexer_peek(lexer, 1) == '-') lexer_adv(lexer); return lexer_adv_with(lexer, init_token("=-", TK_EQUAL_MINUS)); 
        if(lexer_peek(lexer, 1) == '*') lexer_adv(lexer); return lexer_adv_with(lexer, init_token("=*", TK_EQUAL_MULTI)); 
        if(lexer_peek(lexer, 1) == '/') lexer_adv(lexer); return lexer_adv_with(lexer, init_token("=/", TK_EQUAL_DIVI)); 
        if(lexer_peek(lexer, 1) == '%') lexer_adv(lexer); return lexer_adv_with(lexer, init_token("=%", TK_EQUAL_MODULUS)); 
        if(lexer_peek(lexer, 1) == '=') lexer_adv(lexer); return lexer_adv_with(lexer, init_token("==", TK_EQUAL_EQUAL)); 
        return lexer_adv_with(lexer, init_token("=", TK_EQUAL));
      } break;
      case '(': return lexer_adv_current(lexer, TK_LPAREN);
      case ')': return lexer_adv_current(lexer, TK_RPAREN);
      case '{': return lexer_adv_current(lexer, TK_LBRACE);
      case '}': return lexer_adv_current(lexer, TK_RBRACE);
      case ':': return lexer_adv_current(lexer, TK_COLON);
      case ',': return lexer_adv_current(lexer, TK_COMMA);
      case '+': return lexer_adv_current(lexer, TK_PLUS);
      case '*': return lexer_adv_current(lexer, TK_MULTI);
      case '\0': return lexer_adv_current(lexer, TK_EOF);
      default: printf("[Lexer] Unexpected character: %c", lexer->c); exit(1); break;
    }
  }
  return init_token(0, TK_EOF);
}