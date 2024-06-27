
%{
	#include<stdio.h>
%}

%%
"hi" {printf("By");}
.* {printf("wrong");}
%%
int main()
{
	printf("enter i/p");
	yylex();
	
}
int yywrap()
{return 1;}