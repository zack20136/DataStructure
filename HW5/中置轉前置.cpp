#include <stdio.h> 
#include <stdlib.h> 
#define max 50 

int pri(char op){//����B��l�u���� 
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

void pre(char* input){//���m��e�m 
	char stack[max]={'\0'};//�ΨӦs���|���}�C 
	char temp[max]={'\0'};//�ΨӼȦs�r�ꪺ�}�C 
    int i=0,j=0,top=0;//�ΨӹB�⪺�ܼ� 
    while(input[i]!='\0'){//�p��input������ 
    	i++;
	}
	i--;

    while(1){//��i�p��0�ɡA���X 
        switch(input[i]){//�P�_input[i]�̭��O�ƻ� 
            case ')'://��J��^�ɡA���� 
                if(top<(sizeof(stack)/sizeof(char))){//��stack�٦s���U�ȮɡA���� 
                    stack[++top]=input[i];//�Ninput[i]���ȩ�Jstack�� 
                } 
                break;//���X
            case '+': 
			case '-': 
			case '*': 
			case '/': 
			case '%'://��J��+ - * / %�ɡA���� 
                while(pri(stack[top])>pri(input[i])){//��stack[top]���u���פj��input[i]�ɡA���� 
					temp[j++]=stack[top--];//�Nstack[top]���Ȧs�Jtemp�� 
                } 
                if(top<(sizeof(stack)/sizeof(char))){//��stack�٦s���U�ȮɡA���� 
                    stack[++top]=input[i];//�Ninput[i]���ȩ�Jstack�� 
                } 
                break;//���X 
            case '('://��J��^�ɡA���� 
                while(stack[top]!=')'){//��stack[top]������^�ɡA���� 
					temp[j++]=stack[top--];//�Nstack[top]���Ȧs�Jtemp��
                } 
                top--;
                break;//���X 
            default://��L 
				temp[j++]=input[i];//�Ninput[i]���Ȧs�Jtemp��
                break;//���X 
        }
		if(i==0){//��i=0�ɡA���� 
			while(top>0){//��top�j��0�ɡA���� 
				temp[j++]=stack[top--];//�Nstack�Ѿl���Ȧs�Jtemp��
			}
			for(int a=0;input[a]!='\0';a++)//�Ninput�k�s 
				input[a]='\0';
			int k=0;//�stemp���ת��ܼ� 
			while(temp[k]!='\0'){//�p��temp������ 
				input[k++]='\0';
			}
			for(int a=0;a<k;a++){//�Ntemp���ȤϹL�ө�binput�� 
				input[a]=temp[k-a-1];
			}
			break;//���X�禡 
		}
        i--;
    }
}

int main(){ 
    char str[max]={'\0'};//�s��J�r�ꪺ�}�C 
    printf("���m����J�G");//��J 
    scanf("%s",str); 
    
    pre(str);//�I�s���m��e�m�禡 
	printf("�e�m����X�G");//��X 
	printf("%s\n",str);
	
    return 0; 
} 
