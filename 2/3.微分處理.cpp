#include<stdio.h>
#include<stdlib.h>

typedef struct num{
	int cofficient;
	int power;
};

int main(){
	int n;
	num *num1=(num*)malloc(sizeof(num)*n);
	
	printf("give me a nimber:");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("\nCoefficient:");
		scanf("%d",&num1[i].cofficient);
		printf("Power:");
		scanf("%d",&num1[i].power);
		if((num1[i].cofficient==0)&&(num1[i].power==0)){
			break;
		}
	}
	
	for(int i=0;i<n;i++){
		if(i==0){
			printf("\n%dx^%d",num1[i].cofficient,num1[i].power);
		}
		else{
			printf(" + %dx^%d",num1[i].cofficient,num1[i].power);
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			if(num1[j].power<num1[j+1].power){
				num temp=num1[j];
				num1[j]=num1[j+1];
				num1[j+1]=temp;
			}
		}
	}
	
	for(int i=0;i<n;i++){
		if(i==0){
			printf("\n%dx^%d",num1[i].cofficient,num1[i].power);
		}
		else{
			printf(" + %dx^%d",num1[i].cofficient,num1[i].power);
		}
	}
	
	int c=0;
	while(num1[0].cofficient!=0){
		printf("\n%d¶¥:",c);
		c++;
		
		for(int i=0;i<n;i++){
			if(i==0){
				printf("%dx^%d",num1[i].cofficient,num1[i].power);
			}
			else{
				printf(" + %dx^%d",num1[i].cofficient,num1[i].power);
			}
		}
		
		for(int i=0;i<n;i++){
			num1[i].cofficient=num1[i].cofficient*num1[i].power;
			num1[i].power=num1[i].power-1;
		}
		
		if(num1[n-1].power<0){
			n--;
		}
	}
	printf("\n%d¶¥:0",c);
	
	
	return 0;
}
