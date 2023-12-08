#ifndef __SSCRIPT_AST_H__
#define __SSCRIPT_AST_H__


typedef struct SSCRIPT_AST_STRUCT
{
  enum {
    AST_COMPOUND,
    AST_FUNCTION_DEFINATION,
    AST_VARIABLE,
    AST_STATEMENT,
    AST_NOOP,
    AST_DEFINATION_TYPE
  } type;
} SS_AST;

SS_AST* init_ast(int type);

#endif // __SSCRIPT_AST_H__