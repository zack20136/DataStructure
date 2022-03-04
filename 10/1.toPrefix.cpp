#include <stdio.h> 
#include <stdlib.h> 
#define max 50 

int pri(char op){ 
    switch(op){ 
        case '+': 
		case '-': 
			return 1;
        case '*': 
		case '/': 
		case '%':  
			return 2;
        default: 
			return 0;
    } 
} 

void pre(char* input){
	char stack[max]={'\0'}; 
	char temp[max]={'\0'}; 
    int i=0,j=0,top=0;
    while(input[i]!='\0'){
    	i++;
	}
	i--;

    while(1){
        switch(input[i]){
            case ')': 
                if(top<(sizeof(stack)/sizeof(char))){
                    stack[++top]=input[i];
                } 
                break;
            case '+': 
			case '-': 
			case '*': 
			case '/': 
			case '%':
                while(pri(stack[top])>pri(input[i])){ 
					temp[j++]=stack[top--];
                } 
                if(top<(sizeof(stack)/sizeof(char))){ 
                    stack[++top]=input[i]; 
                } 
                break; 
            case '(':
                while(stack[top]!=')'){
					temp[j++]=stack[top--];
                } 
                top--;
                break;
            default:
				temp[j++]=input[i];
                break;
        }
		if(i==0){
			while(top>0){
				temp[j++]=stack[top--];
			}
			for(int a=0;input[a]!='\0';a++)
				input[a]='\0';
			int k=0;
			while(temp[k]!='\0'){
				input[k++]='\0';
			}
			for(int a=0;a<k;a++){
				input[a]=temp[k-a-1];
			}
			break;
		}
        i--;
    }
}

int cal(char *input){
	int num[max]={0}; 
	int i;
	for(i=0;input[i]!='\0';i++){
		switch(input[i]){
			case '+': 
			case '-': 
        	case '*': 
			case '/': 
			case '%':
				num[i]=-9999;
				break; 
        	default:
				num[i]=input[i]-'0';
				break;
		}
	}
	for(int j=0;j<i;j++){
		if((num[j]!=-9999)&&(num[j+1]!=-9999)){
			switch(input[j-1]){
				case '+':
					num[j-1]=num[j]+num[j+1];
					break;
				case '-':
					num[j-1]=num[j]-num[j+1];
					break;
        		case '*':
					num[j-1]=num[j]*num[j+1];
					break;
				case '/':
					num[j-1]=num[j]/num[j+1];
					break;
				case '%':
					num[j-1]=num[j]%num[j+1];
					break;
			}
			for(int k=j;k<i;k++){
				input[k]=input[k+2];
				input[k+1]=input[k+3];
				num[k]=num[k+2];
				num[k+1]=num[k+3];
			}
			i-=2;
			j=0;
		}
	}
	return num[0];
}

int main(){
	FILE *fp=fopen("test.txt","r");
	
	while(!feof(fp)){
		char str[max]={'\0'};
	    fscanf(fp,"%s",str);
	    printf("Infix¡G");
	    printf("%s\n",str);
	    
	    pre(str);
		printf("Perfix¡G");
		printf("%s\n",str);
		
		int ans=cal(str);
		printf("Result¡G");
		printf("%d\n\n",ans);
	}
	
	fclose(fp);
	
    return 0; 
} 
