#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
	int num;
	node *next;
};

node *new_node(int key){
	node *newnode;
	newnode=(node*)malloc(sizeof(node));
	newnode->num=key;
	newnode->next=NULL;
	return newnode;
}

int main(){
	FILE *fp=fopen("input.txt","r");
	if(fp==NULL){
		printf("ERROR\n");
	}
	printf("Adjacency Matrix\n");
	int temp;
	int size=0;
	while(fscanf(fp,"%d",&temp)!=-1){
		size++;
	}
	size=sqrt(size);
	
	rewind(fp);
	int array[size][size];
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			array[i][j]=0;
			fscanf(fp,"%d",&array[i][j]);
			printf("%d ",array[i][j]);
		}
		printf("\n");
	}
	
	node *list[size];
	for(int i=0;i<size;i++){
		list[i]=new_node(i);
	}
	
	node *tmp,*ptr;
	for(int i=0;i<size;i++){
		ptr=list[i];
		for(int j=0;j<size;j++){
			if(array[i][j]==1){
				tmp=new_node(j);
				ptr->next=tmp;
				ptr=ptr->next;
			}
		}
	}
	
	printf("\nAdjacency List\n");
	for(int i=0;i<size;i++){
		int flag=0;
		ptr=list[i];
		while(ptr!=NULL){
			if(flag==0){
				printf("%d ",ptr->num);
				flag=1;
			}
			else{
				printf("-> %d ",ptr->num);
			}
			ptr=ptr->next;
		}
		printf("\n");
	}
	
	printf("\nDFS: ");
	ptr=list[0];
	printf("%d",ptr->num);
	while(ptr->next!=NULL){
		tmp=list[ptr->next->num];
		while(tmp!=NULL){
			if(tmp->num>ptr->num){
				printf(",%d",tmp->num);
			}
			tmp=tmp->next;
		}
		ptr=ptr->next;
	}
	
	printf("\nBFS: ");
	ptr=list[0];
	printf("%d",ptr->num);
	while(ptr!=NULL){
		tmp=list[ptr->num];
		while(tmp!=NULL){
			if(tmp->num>ptr->num){
				printf(",%d",tmp->num);
			}
			tmp=tmp->next;
		}
		ptr=ptr->next;
	}
	
	return 0;
}
