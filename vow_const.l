
%{
	#include<stdio.h>
	int vow_count=0;
	int const_count=0;
%}

%%
[aeiouAEIOU] {vow_count+=1;}
[a-zA-Z] {const_count+=1;}
\n {return 0;}
%%
int yywrap(){return 1;}
int main()
{
	printf("enter string:");
	
	yylex();
	printf("consonant count=%d",const_count);
	printf("vowels count=%d",vow_count);
	return 0;
}
