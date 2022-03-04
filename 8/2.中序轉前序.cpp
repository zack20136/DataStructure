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

void change(char* input){
	char stack[max] = {'\0'}; 
    int i=0;
    while(input[i]!='\0'){
    	i++;
	}
	i--;
    int top = 0;
	char buf[max] ={'\0'};
	int j = 0;

    while(1) {
        switch(input[i]) {
            case ')': 
                if(top < (sizeof(stack) / sizeof(char))) { 
                    top++; 
                    stack[top] = input[i]; 
                } 
                break; 
            case '+': case '-': case '*': case '/': 
                while(priority(stack[top]) > priority(input[i])) { 
					buf[j] = stack[top];
					j++;
                    top--; 
                } 
                if(top < (sizeof(stack) / sizeof(char))) { 
                    top++; 
                    stack[top] = input[i]; 
                } 
                break; 
            case '(': 
                while(stack[top] != ')') { 
					buf[j] = stack[top];
					j++;
                    top--; 
                } 
                top--;
                break; 
            default:
				buf[j] = input[i];
				j++;
                break; 
        }
		if(i == 0){
			while(top > 0) {  
				buf[j] = stack[top];
				j++;
				top--; 
			}
			buf[j] = '\0';
			char temp[max];
			int k=0;
			while(buf[k]!='\0'){
				k++;
			}
			for(int a=0;a<k;a++){
				temp[a]=buf[k-a-1];
			}
			printf("¿é¥X¡G");
			printf("%s\n", temp);
			break;
		}
        i--;
    }
}

int main(void){ 
    char input[max]={'\0'}; 
    
    printf("¿é¤J¡G"); 
    scanf("%s",input); 
    change(input);

    return 0; 
} 
