#include<stdio.h>
#include<stdlib.h>

int MAX(int a,int b){
	int c;
	while(b!=0){
		c=a%b;
		a=b;
		b=c;
	}
	return a;
}

int MIN(int a,int b,int c){
	return a*b/c;
}

int main(){
	int num1=1,num2=1;
	int max,min;
	
	while((num1!=0)||(num2!=0)){
		printf("块ㄢ计");
		scanf("%d%d",&num1,&num2);
		if((num1==0)&&(num2==0)){
			break;
		}
		max=MAX(num1,num2);
		min=MIN(num1,num2,max);
		printf("程そ计%d\n",max);
		printf("程そ计%d\n",min);
	}
	
	return 0;
}
