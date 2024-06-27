
%{
	#include<stdio.h>
%}

%%
">"|"<"|">="|"<="|"=="|"!=" {printf("entered operator is a relational operator");}
.* printf("wrong");
%%
int main()
{
	printf("enter input ");
	yylex();
	return 0;
}
int yywrap(){return 1;}