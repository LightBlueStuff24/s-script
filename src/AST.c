#include "./include/AST.h"
#include <stdlib.h>

SS_AST* init_ast(int type)
{
  SS_AST* ast = calloc(1, sizeof(struct SSCRIPT_AST_STRUCT));
  ast->type = type;
  
  return ast;
}