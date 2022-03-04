#include<stdio.h>
#include<stdlib.h>

struct node{
	int num;
	int power;
	node *next;
};

node *new_node(int a,int b){
	node *newnode=(node*)malloc(sizeof(node));
	newnode->num=a;
	newnode->power=b;
	newnode->next=NULL;
	return newnode;
}

node *f1=NULL;
node *f2=NULL;
node *ptr;
node *pre;

void sort(node *f){
	int n=0,c=0;
	while(n<=c){
		ptr=f;
		while(ptr->next!=NULL){
			pre=ptr;
			ptr=ptr->next;
			if(ptr->num==0){
				pre->next=ptr->next;
				ptr=pre;
			}
			else if(ptr->power>pre->power){
				int temp=ptr->num;
				ptr->num=pre->num;
				pre->num=temp;
				temp=ptr->power;
				ptr->power=pre->power;
				pre->power=temp;
			}
			if(n==0){
				c++;
			}
		}
		n++;
	}
}

int main(){
	int flag=0;
	int in1,in2;
	for(int i=1;i<=2;i++){
		in1=1,in2=1;
		ptr=f2=NULL;
		while((in1!=0)||(in2!=0)){
			flag=0;
			pre=ptr;
			ptr=f2;
			printf("輸入多項式%d(係數 次方):",i);
			scanf("%d%d",&in1,&in2);
			while(ptr!=NULL){
				if(in2==ptr->power){
					printf("此次方已存在\n");
					flag=1;
					break;
				}
				ptr=ptr->next;
			}
			if(flag==1){
				ptr=pre;
				continue;
			}
			ptr=pre;
			node *add=new_node(in1,in2);
			if(ptr==NULL){
				f2=add;
				ptr=f2;
			}
			else{
				ptr->next=add;
				ptr=ptr->next;
			}
		}
		
		sort(f2);
		
		ptr=f2;
		printf("多項式%d為:",i);
		if(ptr->num==0){
			printf("多項式沒東西\n");
		}
		else{
			printf("%dx^%d",ptr->num,ptr->power);
			ptr=ptr->next;
			while(ptr!=NULL){
				printf(" + %dx^%d",ptr->num,ptr->power);
				ptr=ptr->next;
			}
			printf("\n");
		}
		if(f1==NULL){
			f1=f2;
		}
	}
	
	node *temp;
	ptr=f1;
	while(ptr!=NULL){
		pre=f2;
		temp=pre;
		while(pre!=NULL){
			if(ptr->power==pre->power){
				ptr->num=ptr->num+pre->num;
				temp->next=pre->next;
				break;
			}
			temp=pre;
			pre=pre->next;
		}
		temp=ptr;
		ptr=ptr->next;
	}
	
	ptr=temp;
	pre=f2;
	while(pre!=NULL){
		ptr->next=pre;
		ptr=ptr->next;
		pre=pre->next;
	}
	
	sort(f1);
	
	ptr=f1;
	printf("%dx^%d",ptr->num,ptr->power);
	ptr=ptr->next;
	while(ptr!=NULL){
		printf(" + %dx^%d",ptr->num,ptr->power);
		ptr=ptr->next;
	}
	printf("\n");
	
	return 0;
}
