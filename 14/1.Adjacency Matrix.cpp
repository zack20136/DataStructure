#include<stdio.h>
#include<stdlib.h>

int main(){
	int node,edge;
	while(1){
		int num1,num2;
		printf("Insert the number of nodes :");
		scanf("%d",&node);
		if(node==0)
			break;
		int array[node][node];
		for(int i=0;i<node;i++){
			for(int j=0;j<node;j++){
				array[i][j]=0;
			}
		}
		printf("Insert the number of edges :");
		scanf("%d",&edge);
		for(int i=0;i<edge;i++){
			printf("Insert the edge%d :",i+1);
			scanf("%d%d",&num1,&num2);
			array[num1][num2]=1;
		}
		for(int i=0;i<node;i++){
			for(int j=0;j<node;j++){
				printf("%d ",array[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
