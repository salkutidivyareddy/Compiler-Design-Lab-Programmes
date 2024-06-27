#include<stdio.h>
#include<string.h>

struct productions{
	char left[20];
	char right[20];
};

int main(){
	char *token1,*token2,*substring,ch[2],stack[50],temp[50],input[20];
	struct productions rules[10];
	int i,j,k,rule_count=0,substring_len,stack_len,stack_top;
	
	stack[0] = '\0';
	
	printf("enter no of productions:");
	scanf("%d",&rule_count);
	
	printf("enter productions left->right:\n");
	for(i=0;i<rule_count;i++){
		scanf("%s",temp);
		token1 = strtok(temp,"->");
		token2 = strtok(NULL,"->");
		strcpy(rules[i].left,token1);
		strcpy(rules[i].right,token2);
	}
	
	printf("enter input string:");
	scanf("%s",input);
	
    i=0;
	while(1){
		if(i<strlen(input)){
		  ch[0] = input[i];
		  ch[1] = '\0';
		  i++;
		  strcat(stack,ch);
		  printf("%s\t",stack);
		  for(k=i;k<strlen(input);k++){
			printf("%c",input[k]);
		  }
		  printf("\tshift %s\n",ch);	
		}
		
		for(j=0;j<rule_count;j++){
			substring = strstr(stack,rules[j].right);
			if(substring!=NULL){
				stack_len = strlen(stack);
				substring_len = strlen(substring);
				stack_top = stack_len - substring_len;
				stack[stack_top] = '\0';
				strcat(stack,rules[j].left);
				printf("%s\t",stack);
				for(k=i;k<strlen(input);k++){
			     printf("%c",input[k]);
		        }
		        printf("\treduce %s->%s\n",rules[j].left,rules[j].right);	
		        j = -1;
			}
		}
		
		if(strcmp(stack,rules[0].left)==0 && i==strlen(input)){
			printf("\nAccepted");
			break;
		}
		
		if(i==strlen(input)){
			printf("\nNot Accepted");
			break;
		}
	}
	return 0;

}

