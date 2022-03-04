#include <stdio.h> 
#include <stdlib.h> 
#define max 50 

int pri(char op){//比較運算子優先度 
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

void pre(char* input){//中置轉前置 
	char stack[max]={'\0'};//用來存堆疊的陣列 
	char temp[max]={'\0'};//用來暫存字串的陣列 
    int i=0,j=0,top=0;//用來運算的變數 
    while(input[i]!='\0'){//計算input的長度 
    	i++;
	}
	i--;

    while(1){//當i小於0時，跳出 
        switch(input[i]){//判斷input[i]裡面是甚麼 
            case ')'://當遇到）時，執行 
                if(top<(sizeof(stack)/sizeof(char))){//當stack還存的下值時，執行 
                    stack[++top]=input[i];//將input[i]的值放入stack裡 
                } 
                break;//跳出
            case '+': 
			case '-': 
			case '*': 
			case '/': 
			case '%'://當遇到+ - * / %時，執行 
                while(pri(stack[top])>pri(input[i])){//當stack[top]的優先度大於input[i]時，執行 
					temp[j++]=stack[top--];//將stack[top]的值存入temp裡 
                } 
                if(top<(sizeof(stack)/sizeof(char))){//當stack還存的下值時，執行 
                    stack[++top]=input[i];//將input[i]的值放入stack裡 
                } 
                break;//跳出 
            case '('://當遇到）時，執行 
                while(stack[top]!=')'){//當stack[top]不等於）時，執行 
					temp[j++]=stack[top--];//將stack[top]的值存入temp裡
                } 
                top--;
                break;//跳出 
            default://其他 
				temp[j++]=input[i];//將input[i]的值存入temp裡
                break;//跳出 
        }
		if(i==0){//當i=0時，執行 
			while(top>0){//當top大於0時，執行 
				temp[j++]=stack[top--];//將stack剩餘的值存入temp裡
			}
			for(int a=0;input[a]!='\0';a++)//將input歸零 
				input[a]='\0';
			int k=0;//存temp長度的變數 
			while(temp[k]!='\0'){//計算temp的長度 
				input[k++]='\0';
			}
			for(int a=0;a<k;a++){//將temp的值反過來放在input裡 
				input[a]=temp[k-a-1];
			}
			break;//跳出函式 
		}
        i--;
    }
}

int main(){ 
    char str[max]={'\0'};//存輸入字串的陣列 
    printf("中置式輸入：");//輸入 
    scanf("%s",str); 
    
    pre(str);//呼叫中置轉前置函式 
	printf("前置式輸出：");//輸出 
	printf("%s\n",str);
	
    return 0; 
} 
