%option noyywrap
%{
	#include<stdio.h>
%}

%%
\/\/(.*) {};
\/\*(.*\n)*.*\*\/ {};
%%
int main()
{
	yyin=fopen("input.c","r");
	yyout=fopen("out.c","w");
	yylex();
	return 0;
}