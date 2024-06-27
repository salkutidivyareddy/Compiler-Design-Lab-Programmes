#include<stdio.h>
#include<ctype.h>

void first(char[],char );
void addtoresult(char[],char );
int count;
char a[20][20];

int main(){
	int i;
	char c,choice;
	char result[20];
	
	printf("enter no of profuctions:");
	scanf("%d",&count);
	
	for(i=0;i<count;i++){
	   printf("enter production:%d ",i+1);
	   scanf("%s",a[i]);
    }
    
    do{
    	printf("find the first of :");
    	scanf("%c",&c);
    	scanf("%c",&c);
    	first(result,c);
    	printf("first(%c)={",c);
    	for(i=0;result[i]!='\0';i++)
    		printf("%c ",result[i]);
    	printf("}\n");
		printf("Do you want to continue?(y or n)");
		scanf("%c",&choice);
		scanf("%c",&choice);
	}while(choice=='y'||choice=='Y');
}

void first(char* result,char c){
	 char subresult[20];
	 result[0] = '\0';
	 subresult[0] = '\0';
	 int i,k,j;
	 int foundepsilon;
	 
	 if(!(isupper(c))){
	 	addtoresult(result,c);
	 	return;
	 }
	 
	 for(i=0;i<count;i++){
	    if(a[i][0] == c){
	   	  if(a[i][2] == '$')
	 	    addtoresult(result,'$');
	      else{
	    	j=2;
	    	while(a[i][j]!='\0'){
			    foundepsilon = 0;
	    		
	    		first(subresult,a[i][j]);
	    		
	    		for(k=0;subresult[k]!='\0';k++){
	    			addtoresult(result,subresult[k]);
				}
				
				for(k=0;subresult[k]!='\0';k++)
				  if(subresult[k] == '$'){
				  	foundepsilon = 1;
				  	break;
				  }
				  
				if(!(foundepsilon))
				break;
				
				j++;
			}
		  }   
	   }
	 }
	return;	
}

void addtoresult(char result[],char val){
	int k;
	for(k=0;result[k]!='\0';k++)
		if(result[k] == val)
		return;
	result[k] = val;
	result[k+1] = '\0';
}
