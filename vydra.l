%top{
  #include "token.h"
}

%option yylineno

NUMBER    [0-9]*\.?[0-9]+
PERIOD    [.]
SYMBOL    [a-zA-Z_-]+

%%

{NUMBER}  {
            printf("Found number (%s)\n", yytext);
            new_token(TOKEN_NUMBER, yylineno, yytext);
          }

{SYMBOL}  {
            printf("Found symbol (%s)\n", yytext, yylineno);
            new_token(TOKEN_SYMBOL, yylineno, yytext);
          }

{PERIOD}  {
            printf("Found period\n");
            new_token(TOKEN_PERIOD, yylineno, yytext);
          }

\n        {
            /* Match newline for yylineno */
          }

%%

int
main(int argc, char **argv)
{
  init_tokens();
  yyin = fopen(argv[1], "r");
  yylex();
}
