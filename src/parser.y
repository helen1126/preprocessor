%{
#include <iostream>
#include <string>
#include "preprocessor.h"

extern int yylex();
extern void yyerror(const char* msg);
%}

%union {
    double num;
    char* str;
}

%token <str> ATTRIBUTE
%token <num> WEIGHT
%token LPAREN RPAREN COLON

%start input

%%
input:
    | input expr { /* 处理解析结果 */ }
    ;

expr:
    LPAREN ATTRIBUTE COLON WEIGHT RPAREN {
        std::cout << "属性: " << $2 << ", 权重: " << $4 << std::endl;
        free($2);  // 释放Flex分配的内存
    }
    ;
%%

void yyerror(const char* msg) {
    std::cerr << "语法错误: " << msg << std::endl;
}