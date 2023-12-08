#include "./include/Token.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

SS_TOKEN* init_token(char* value, int type) {
  SS_TOKEN* ss_token = calloc(1, sizeof(struct TOKEN_SSCRIPT_STRUCT));
  ss_token->value = value;
  ss_token->type = type;
  return ss_token;
}

const char* token_type_to_str(int type)
{
  switch(type) {
    case TK_EOF: return "TK_EOF";
    case TK___MAIN__: return "TK___MAIN__";
    case TK_LPAREN: return "TK_LPAREN";
    case TK_RPAREN: return "TK_RPAREN";
    case TK_LBRACE: return "TK_LBRACE";
    case TK_RBRACE: return "TK_RBRACE";
    case TK_NUMERIC: return "TK_NUMERIC";
    case TK_IDENTIFIER: return "TK_IDENTIFIER";
    case TK_KEYWORD: return "TK_KEYWORD";
    case TK_INT: return "TK_INT";
    case TK_FLOAT: return "TK_FLOAT";
    case TK_CHAR: return "TK_CHAR";
    case TK_STRING: return "TK_STRING";
    case TK_BOOL: return "TK_BOOL";
    case TK_CONST: return "TK_CONST";
    case TK_VOID: return "TK_VOID";
    case TK_EQUAL: return "TK_EQUAL";
    case TK_PLUS: return "TK_PLUS";
    case TK_MINUS: return "TK_MINUS";
    case TK_MULTI: return "TK_MULTI";
    case TK_DIVI: return "TK_DIVI";
    case TK_MODULUS: return "TK_MODULUS";
    case TK_EQUAL_EQUAL: return "TK_EQUAL_EQUAL";
    case TK_LESS_EQUAL: return "TK_LESS_EQUAL";
    case TK_GREATER_EQUAL: return "TK_GREATER_EQUAL";
    case TK_ARROW_LEFT: return "TK_ARROW_LEFT";
    case TK_ARROW_RIGHT: return "TK_ARROW_RIGHT";
    case TK_PLUS_EQUAL: return "TK_PLUS_EQUAL";
    case TK_MINUS_EQUAL: return "TK_MINUS_EQUAL";
    case TK_MULTI_EQUAL: return "TK_MULTI_EQUAL";
    case TK_DIVI_EQUAL: return "TK_DIVI_EQUAL";
    case TK_MODULUS_EQUAL: return "TK_MULTI_EQUAL";
    case TK_EQUAL_PLUS: return "TK_EQUAL_PLUS";
    case TK_EQUAL_MINUS: return "TK_EQUAL_MINUS";
    case TK_EQUAL_MULTI: return "TK_EQUAL_MULTI";
    case TK_EQUAL_DIVI: return "TK_EQUAL_DIVI";
    case TK_EQUAL_MODULUS: return "TK_EQUAL_MODULUS";
    case TK_COLON: return "TK_COLON";
    case TK_COMMA: return "TK_COMMA";
    case TK_FUNC_ARROW: return "TK_FUNC_ARROW";
    case TK_FUNC: return "TK_FUNC";
    case TK_CLASS: return "TK_CLASS";
    case TK_STRUCT: return "TK_STRUCT";
    case TK_OF: return "TK_OF";
    case TK_IN: return "TK_IN";
    case TK_IF: return "TK_IF";
    case TK_ELSE: return "TK_ELSE";
    case TK_SWITCH: return "TK_SWITCH";
    case TK_CASE: return "TK_CASE";
    case TK_BREAK: return "TK_BREAK";
    case TK_LOOPEACH: return "TK_LOOPEACH";
    case TK_UNTIL: return "TK_UNTIL";
    case TK_FOR: return "TK_FOR";
  }
  return "not_stringable";
}

char* token_to_str(SS_TOKEN* token)
{
  const char* type_str = token_type_to_str(token->type);
  const char* template = "{ type: %s, int_type: %d, value: \"%s\" }";
  char* str = calloc(strlen(type_str) + strlen(template) + 8, sizeof(char));
  sprintf(str, template, type_str, token->type, token->value);
  return str;
}

char anyofchar(char c, char arr[]) {
    int i = 0;
    while (arr[i] != '\0') {
        if (c == arr[i]) {
            return c;
        }
        i++;
    }
  // Return some default value if 'c' is not found in the array.
    return '\0';
}
