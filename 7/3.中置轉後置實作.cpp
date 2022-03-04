#include <stdio.h> 
#include <stdlib.h> 
#define max 100

int priority(char op){
    switch(op){ 
        case '+': 
		case '-': 
			return 1;
        case '*': 
		case '/': 
			return 2;
        default: 
			return 0;
    } 
} 

void change(char* input,char* output){
    char stack[max] ={'\0'};
    int i,j,top;
    for(i=0,j=0,top=0;input[i]!='\0';i++){
		switch(input[i]){
	        case '(':
	            stack[++top]=input[i]; 
	            break; 
	        case '+': 
			case '-': 
			case '*': 
			case '/': 
	            while(priority(stack[top])>=priority(input[i])){ 
	                output[j++]=stack[top--];
	            } 
	            stack[++top]=input[i];
	            break; 
	        case ')': 
	            while(stack[top]!='(') {
	                output[j++]=stack[top--];
	            } 
	            top--; 
	            break; 
	        default:
	            output[j++]=input[i];
	    }    
    }
    while(top>0){ 
        output[j++]=stack[top--];
    }
} 

int main(void){ 
    char input[max]={'\0'}; 
    char output[max]={'\0'}; 

    printf("¿é¤J¡G\n"); 
    scanf("%s",input); 
    change(input,output);
    printf("¿é¥X¡G\n");
    for(int i=0;output[i]!='\0';i++){
        printf("%c",output[i]); 
    }

    return 0; 
} 
