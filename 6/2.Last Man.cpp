#include<stdio.h>
#include<stdlib.h>

int main(){
	
	while(1){
		int num,fav,ans=0;
		printf("seat of classroom�G");
		scanf("%d",&num);
		printf("teacher fav num�G");
		scanf("%d",&fav);
		if((num==0)&&(fav==0)){
			break;
		}
		if((num>1)&&(fav>1)){
     		for(int i=2;i<=num;i++)
      			ans=(ans+fav)%i;
			printf("best position:%d\n",ans+1);
		}
		else{
			printf("S���j��1�AN���j��1\n");
		}
	}	
	return 0;
} 

