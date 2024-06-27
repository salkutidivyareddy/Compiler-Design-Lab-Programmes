
%{
	#include<stdio.h>
	int lc=1,sc=0,wc=0,c=0,ch=0;
%}

%%
\n {lc++;}
([ ]) {sc++;}
[a-zA-Z0-9]+ {wc++;c=c+yyleng;}
"$" {return 1;}
. {c++;ch++;}

%%
int main()
{
	printf("enter input:");
	yylex();
	printf("\nLines Count: %d\nSpaces Count: %d\nWords Count: %d\nCharacter Count:(without counting spaces): %d",lc,sc,wc,c);
	return 0;
}
int yywrap(){return 1;}