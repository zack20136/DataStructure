#include <stdio.h>
#include <stdlib.h>

int pri(char op){ 
    switch(op){ 
        case '+': 
		case '-': 
			return 1;
        case '*': 
		case '/':  
		case '^':
			return 2;
        default: 
			return 0;
    } 
} 

void pre(char* input){
	char stack[50]={'\0'}; 
	char temp[50]={'\0'}; 
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
			case '^': 
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
	int num[50]={0}; 
	int i,temp;
	for(i=0;input[i]!='\0';i++){
		switch(input[i]){
			case '+': 
			case '-': 
        	case '*': 
			case '/': 
			case '^':
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
				case '^':
					temp=num[j];
					num[j-1]=num[j];
					for(int k=0;k<num[j+1]-1;k++){
						num[j-1]=num[j-1]*temp;
					}
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

void judge(char *input){
	int flag=0,top=0;
	int num[50]={0};
	int i;
	for(i=0;input[i]!='\0';i++){
		switch(input[i]){
			case '+':
			case '-':
			case '*':
			case '/':
			case '^':
				num[i]=-9999;
				break;
			case '(':
			case ')':
				num[i]=-10000;
				break;
			default:
				num[i]=input[i]-'0';
				break;
		}
	}
	num[i]=-99999;
	
	for(i=0;input[i]!='\0';i++){
		switch(input[i]){
			case '+':
			case '-':
			case '*':
			case '/':
				if((num[i-1]==-9999)||(num[i+1]==-9999)||(num[i+1]==-99999)){
					flag=2;
					goto A;
				}	
				break;
			case '(':
				top=1;
				break;
			case ')':
				if(top!=1){
					flag=3;
					goto A;
				}
				top=0;
				break;
			case '^':
				break;
			default:
				if((input[i]<'0')||(input[i]>'9')){
					flag=1;
					goto A;
				}
				break;
		}	
	}
	
	A:switch(flag){
		case 0:
			pre(input);
			printf("%d => Pass test\n",cal(input));
			break;
		case 1:
			printf("%s => fail:Symbol of operation errors\n",input);
			break;
		case 2:
			printf("%s => fail:The number of symbol errors\n",input);
			break;
		case 3:
			printf("%s => fail:Parentheses errors\n",input);
			break;
	}
}

int main(){
	FILE *fp=fopen("Judging Test-2.txt","r");
	if(fp==NULL)
		return 0;
	printf("File read success,begin test\n");
	printf("----------------------------\n");
	
	int n=0;
	while(!feof(fp)){
		char str[50]={'\0'};
	    fscanf(fp,"%s",str);
	    printf("row %d : ",++n);
	    judge(str);
	}
	
	fclose(fp);
	printf("----------------------------\n");
	printf("File read end,test finish\n");
	
	return 0;
}
