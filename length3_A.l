%option noyywrap
%{
	#include<stdio.h>
%}

%%
[a-zA-Z0-9]+ {fun(yyleng);}
%%
fun(int l){
if(l==3){
if(yytext[0]=='A')printf("%s is starting with A and have length of 3\n",yytext);
}
}
int main()
{
	printf("Enter i/p string:");
	yylex();
	return 0;
}