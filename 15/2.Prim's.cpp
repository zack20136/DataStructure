#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	int num;
	int cost;
	node *next;
};

node *new_node(int num,int cost){
	node *newnode=(node*)malloc(sizeof(node));
	newnode->num=num;
	newnode->cost=cost;
	newnode->next=NULL;
	return newnode;
}

int main(){
	FILE *fp=fopen("input.txt","r");
	if(fp==NULL){
		printf("Error\n");
	}
	int n=0;
	char buf[50];
	while(fgets(buf,50,fp)){//算這個檔案有幾行 
		n++;
	}
	rewind(fp);//回到檔案開頭 
	node *list[n];
	node *ptr,*pre;
	while(fgets(buf,50,fp)){//儲存檔案中的數值 
		char *p=strtok(buf," ");
		int a=atoi(p),b;
		list[a]=new_node(a,1000);
		ptr=list[a];
		p=strtok(NULL," ");
		a=atoi(p);
		for(int i=a;i>0;i--){
			p=strtok(NULL," ");
			a=atoi(p);
			p=strtok(NULL," ");
			b=atoi(p);
			node *temp=new_node(a,b);
			ptr->next=temp;
			ptr=ptr->next;
		}
	}
	
//	for(int i=0;i<n;i++){
//		ptr=list[i];
//		while(ptr!=NULL){
//			printf("%d ",ptr->num);
//			ptr=ptr->next;
//		}
//		printf("\n");
//	} 
	
	node *re[n];//樹 
	node *temp[n];//用來記每個點的位子 
	for(int i=0;i<n;i++){
		re[i]=new_node(i,0);
		temp[i]=re[i];
	}
	
	printf("Prim Algorithm\n--------------\n");
	int min,x,y;
	for(int i=1;i<n;i++){
		min=999;
		node *tmp=re[1];
		while(tmp!=NULL){
			ptr=list[tmp->num];
			while(ptr!=NULL){
				if(ptr->cost<min){
					pre=ptr;
					min=ptr->cost;
					x=tmp->num;
					y=ptr->num;
				}
				ptr=ptr->next;
			}
			tmp=tmp->next;
		}
		printf("%dth : Link:%d-%d Weight:%d\n",i,x,y,min);
		
		for(int j=0;j<n;j++){
			if(re[j]!=NULL){
				ptr=re[j];
				ptr=ptr->next;
				while(ptr!=NULL){
					if(y==ptr->num){
						printf("Waring:It cause the cycle\n");
						i--;
						goto L99;
					}
					ptr=ptr->next;
				}
			}
		}
		
		ptr=temp[x];
		while(ptr->next!=NULL){
			ptr=ptr->next;
		}
		ptr->next=re[y];
		re[y]=NULL;
		
		L99:
		ptr=list[y];
		while(ptr->cost!=pre->cost){
			ptr=ptr->next;
		}
		ptr->cost=999;
		pre->cost=999;
	}
	printf("--------------\nEnd\n");
	
	fclose(fp);
    return 0;
}
