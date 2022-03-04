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

void add(){
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

int del(){
	if(isEmpty()==1){
		printf("堆疊已空\n");
	}
	else{
		stack[0]=NULL;
		n--;
		for(int i=0;i<n;i++){
			stack[i]=stack[i+1];
		}
	}
}

int main(){
	while(1){
		int input;
		printf("[1]新增 [2]刪除 [3]顯示 [0]結束 :");
		scanf("%d",&input);
		if(input==1){
			add();
		}
		else if(input==2){
			del();
		}
		else if(input==3){
			printf("佇列內容:");
			for(int i=0;i<n;i++){
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
