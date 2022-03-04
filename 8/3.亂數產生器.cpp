#include <stdio.h> 
#include <stdlib.h>
#include<time.h>

int rand7(){
	return rand()%7+1;
}

int main(){
	srand(time(NULL));
	int A[10]={0};
	for(int i=0;i<10000;i++){
		int n=(rand7()+rand7()+rand7()+rand7())%10;
		A[n]++;
	}
	for(int i=0;i<10;i++){
		printf("%d => %d\n",i+1,A[i]);
	}
	return 0;
}

