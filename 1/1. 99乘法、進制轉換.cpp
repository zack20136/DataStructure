#include<stdio.h>
#include<stdlib.h>

int main(){
	printf("�Q�i��\n");
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			printf("%5d",i*j);
		}
		printf("\n");
	}
	printf("\n�K�i��\n");
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			printf("%5o",i*j);
		}
		printf("\n");
	}
	printf("\n�Q���i��\n");
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			printf("%5x",i*j);
		}
		printf("\n");
	}
	return 0;
}
