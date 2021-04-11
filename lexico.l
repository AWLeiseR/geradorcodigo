%option noyywrap
%{

    #include <ast.h>
    #include <sintatico.tab.h>
    
    extern YYSTYPE yylval;

}%
%%
"CONSTANT"                  {return CONSTANT;}
"VALUE"                     {return VALUE;}
"VARIABLE"                  {return VARIABLE;}
"GLOBAL"                    {return GLOBAL;}
"TYPE"          {return TYPE;}
"void"          {return VOID;}
"int"           {return INT;}
"char"          {return CHAR;}
"FUNCTION"      {return FUNCTION;}
"RETURN_TYPE"   {return RETURN_TYPE;}
"END_FUNCTION"  {return END_FUNCTION;}
"DO_WHILE"      {return DO_WHILE;}
"IF"            {return IF;}
"WHILE"         {return WHILE;}
"FOR"           {return FOR;}
"PRINTF"        {return PRINTF;}
"SCANF"         {return SCANF;}
"EXIT"          {return EXIT;}
"RETURN"        {return RETURN;}
":"             {return COLON;}
"++"            {return INC;}
"--"            {return DEC;}    
"="             {return ASSIGN;}
"%"             {return REMAINDER;}
"*"             {return MULTIPLY;}
"-"             {return MINUS;}
"+"             {return PLUS;}
";"             {return SEMICOLLON;}
"{"             {return L_CURLY_BRACKET;}
"}"             {return R_CURLY_BRACKET;}
"["             {return L_SQUARE_BRACKET;}
"]"             {return R_SQUARE_BRACKET;}
"("             {return L_PARENTESE;}
")"             {return R_PARENTESE;}
"~"             {return BITWISE_NOT;}
"!"             {return NOT;}
"&"             {return BITWISE_ANF;}
"&&"            {return LOGICAL_AND;}
"-="            {return MINUS_ASSIGN;}
"+="            {return ADD_ASSIGN;}
"<<"            {return L_SHIFT;}
">>"            {return R_SHIFT;}
">="            {return GREATER_EQUAL;}
"<="            {return LESS_EQUAL;}
">"             {return GREATER_THAN;}
"<"             {return LESS_THAN;}
"!="            {return NOT_EQUAL;}
"=="            {return EQUAL;}
"||"            {return LOGICAL_OR;}
"^"                             {return BITWISE_XOR;}
"|"                             {return BITWISE_OR;}
"/"                             {return DIV;}
","                             {return COMMA;}
\"(.)*\"                        {return STRING;}
[']"\\"?.[']                    {return CHARACTER;}
[0-9]+                          {return NUM_INTEGER;}
[_a-zA-Z]+([0-9a-zA-Z]*_*)*     {return IDENTIFIER;}
" "                             {return SPACE;}
%%