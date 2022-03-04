#include<stdio.h>
#include<stdlib.h>
#define max 100

int stack[max];
int n=0;

int isFull(){
	if(n==max){
		return 1;
	}
	return 0;
}

int isEmpty(){
	if(n==0){
		return 1;
	}
	return 0;
}

void push(){
	if(isFull()==1){
		printf("堆疊已滿\n");
	}
	else{
		int input;
		printf("輸入值:");
		scanf("%d",&input);
		stack[n]=input;
		n++;
	}
}

int pop(){
	if(isEmpty()==1){
		printf("堆疊已空\n");
	}
	else{
		stack[n]=NULL;
		n--;
	}
}

int main(){
	while(1){
		int input;
		printf("[1]新增 [2]刪除 [3]顯示 [0]結束 :");
		scanf("%d",&input);
		if(input==1){
			push();
		}
		else if(input==2){
			pop();
		}
		else if(input==3){
			printf("堆疊內容:");
			for(int i=n-1;i>=0;i--){
				printf(" %d",stack[i]);
			}
			if(isEmpty()==1){
				printf(" NULL");
			}
			printf("\n");
		}
		else if(input==0){
			break;
		}
		else{
			printf("輸入錯誤\n");
		}
	}
	
	return 0;
}
