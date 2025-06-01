%{
#include "parser.hpp"  // 改为包含项目生成的 parser.hpp（路径可能需要调整为 build/parser.hpp）
%}

%%
"("                 { return LPAREN; }
")"                 { return RPAREN; }
":"                 { return COLON; }
([\u4E00-\u9FA5a-zA-Z_]+)  { yylval.str = strdup(yytext); return ATTRIBUTE; }  // 新增中文字符支持
([0-9]+(\.[0-9]+)?) { yylval.num = atof(yytext); return WEIGHT; }
[ \t\n]             { /* 忽略空白 */ }
.                   { return yytext[0]; }  // 其他字符
%%

int yywrap() { return 1; }