#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int n=0,count,i=0,j=0;
char pro[10][10],f[10];
void First(char );
void Follow(char );
void main()
{
	int choice;
	char c,ch;
	printf("enter no of productions");
	scanf("%d",&count);
	printf("enter %d productions",count);
	for(i=0;i<count;i++)
		scanf("%s%c",pro[i],&ch);
	do{
	n=0;
	printf("enter element to find follow function");
	scanf("%c",&c);
	Follow(c);
	printf("FOLLOW(%c)={",c);
	for(i=0;i<n;i++)
	printf("%c",f[i]);
	printf("}\n");
	printf("press 1 to continue");
	scanf("%d%c",&choice,&ch);
	}
	while(choice==1);
}
void First(char c)
{
	int j;
	if(!(isupper(c)))
	f[n++]=c;
	for(j=0;j<count;j++)
	{
		if(pro[j][0]==c)
		{
			if(pro[j][2]=='$')
			Follow(pro[j][0]);
			else if(islower(pro[j][2]))
			f[n++]=pro[j][2];
			else
			First(pro[j][2]);
		}
	}
}
void Follow(char c)
{
	if(pro[0][0]==c)
		f[n++]='$';
	for(i=0;i<count;i++)
	{
		for(j=2;j<strlen(pro[i]);j++)
		{
		if(pro[i][j]==c)
		{
			if(pro[i][j+1]!='\0')
				First(pro[i][j+1]);
			 if(pro[i][j+1]=='\0' && c!=pro[i][0])
				Follow(pro[i][0]);
				
		}
		}
	}	
}









