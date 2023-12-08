#ifndef __SS_TOKEN_H__
#define __SS_TOKEN_H__

typedef struct TOKEN_SSCRIPT_STRUCT
{
  char* value;
  enum {
    TK_EOF,
    TK___MAIN__,      // __main__
    TK_LPAREN,        // (
    TK_RPAREN,        // )
    TK_LBRACE,        // }
    TK_RBRACE,        // {
    TK_NUMERIC,       // [0,1,2,3,4,5,6,7,8,9]
    TK_IDENTIFIER,    // [a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,-,&]
                      // [A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,_,#]
    TK_KEYWORD,
    TK_INT,           // int
    TK_FLOAT,         // float
    TK_CHAR,          // char
    TK_STRING,        // string
    TK_BOOL,          // bool
    TK_CONST,         // const
    TK_VOID,          // void
    TK_EQUAL,        // =
    TK_PLUS,          // +
    TK_MINUS,         // -
    TK_MULTI,         // *
    TK_DIVI,          // /
    TK_MODULUS,       // %
    TK_EQUAL_EQUAL,   // ==
    TK_LESS_EQUAL,    // <=
    TK_GREATER_EQUAL, // >=
    TK_ARROW_LEFT,    // <-
    TK_ARROW_RIGHT,   // ->
    TK_PLUS_EQUAL,    // +=
    TK_MINUS_EQUAL,   // -=
    TK_MULTI_EQUAL,   // *=
    TK_DIVI_EQUAL,    // /=
    TK_MODULUS_EQUAL, // %=
    TK_EQUAL_PLUS,    // =+
    TK_EQUAL_MINUS,   // =-
    TK_EQUAL_MULTI,   // =*
    TK_EQUAL_DIVI,    // =/
    TK_EQUAL_MODULUS, // =%
    TK_COLON,         // :
    TK_COMMA,         // ,
    TK_SEMI_COLON,
    TK_FUNC_ARROW,    // =>
    TK_FUNC,          // func
    TK_CLASS,         // class
    TK_STRUCT,        // struct
    TK_OF,            // of
    TK_IN,            // in
    TK_IF,            // if
    TK_ELSE,
    TK_SWITCH,        // switch
    TK_CASE,          // case
    TK_BREAK,         // break
    TK_LOOPEACH,      // loopEach
    TK_UNTIL,         // until
    TK_FOR,           // for
  } type;
} SS_TOKEN; // 

char anyofchar(char c, char arr[]);

SS_TOKEN* init_token(char* value, int type);

char* token_to_str(SS_TOKEN* token);

#endif // __SS_TOKEN_H__