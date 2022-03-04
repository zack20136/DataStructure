#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int top;

void push(int *stack,int x){
	stack[++top]=x;
}

int pop(int *stack){
	int temp=stack[top];
	top--;
	return temp;
}

int main(){
	while(1){
		int stack[100]={0};
		char input[100];
		top=-1;
		printf("¿é¤J¡G");
		scanf("%s",&input);
		if(strcmp(input,"0")==0)
			break;
		int i=0;
		while(input[i]!='\0'){
			if(input[i]=='+'){
				int n1,n2;
				n1=pop(stack);
				n2=pop(stack);
				push(stack,n2+n1);
			}
			else if(input[i]=='-'){
				int n1,n2;
				n1=pop(stack);
				n2=pop(stack);
				push(stack,n2-n1);
			}
			else if(input[i]=='*'){
				int n1,n2;
				n1=pop(stack);
				n2=pop(stack);
				push(stack,n2*n1);
			}
			else if(input[i]=='/'){
				int n1,n2;
				n1=pop(stack);
				n2=pop(stack);
				push(stack,n2/n1);
			}
			else{
				push(stack,input[i]-'0');
			}
			i++;
		}
		printf("%d\n",stack[0]);
	}
	
	return 0;
}
