
%{
	#include<stdio.h>
%}

%%
[+-]?[0-9]+ {printf("\ninteger\n");}
[+-]?[0-9]*"."[0-9]+ {printf("\nFloat\n");}
%%
int main()
{
	printf("enter number");
	yylex();
	return 0;
}
int yywrap(){return 1;}