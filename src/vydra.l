%top{
  #include "token.h"
  #include "object.h"
  #include "string.h"
  #include "io.h"
}

%option yylineno

NUMBER    [0-9]*\.?[0-9]+
SYMBOL    [a-zA-Z_-]+
OPERATOR  [^[:space:]0-9a-zA-Z]+

%%

{NUMBER}    {
              printf("Found number (%s)\n", yytext);
              new_token(TOKEN_NUMBER, yylineno, yytext);
            }

{SYMBOL}    {
              printf("Found symbol (%s)\n", yytext, yylineno);
              new_token(TOKEN_SYMBOL, yylineno, yytext);
            }

{OPERATOR}  {
              printf("Found operator (%s)\n", yytext, yylineno);
              new_token(TOKEN_SYMBOL, yylineno, yytext);
            }

[ \t\n\r]   {

            }

%%

int
main(int argc, char **argv)
{
  init_tokens();
  yyin = fopen(argv[1], "r");
  yylex();

  return eval(tokens);
}
