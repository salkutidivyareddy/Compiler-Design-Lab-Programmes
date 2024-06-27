%{
	#include<stdio.h>
%}
%% 
"hi" {printf("Bye");}
.* {printf("Wrong");}
%%
int yywrap(){return 1;}
int main(){
	printf("enter the string:");
	yylex();
	return 0;
}