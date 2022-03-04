#include<stdio.h>
#include<stdlib.h>

int flag=1;

struct node{
    int data;     
    int lthread;
    int rthread;
    node *left;
    node *right; 
};

node *insert(node *root, int ikey);
node *del(node *root,int dkey);
void cal(int way[]);
void inorder(node *root);

int main(){
	node *root=NULL;
	while(1){
		int input=0;
		printf("MAX threaded binary tree\n--------\n1. Insert\n2. Delete\n3. Print\n4. Print threaded\n--------\nchoose your operation:");
		scanf("%d",&input);
		switch(input){
			case 1://Insert
				while(1){
					scanf("%d",&input);
					if(input==0)
						break;
					root=insert(root,input);
				}
				printf("End Insert\n\n");
				break;
			case 2://Delete
				scanf("%d",&input);
				root=del(root,input);
				printf("Complete Delete\n\n");
				break;
			case 3://Print
				inorder(root);
				printf("\n\n");
				break;
			case 4://Print threaded
				scanf("%d",&input);
				printf("\n\n");
				break;
			default://除錯 
				printf("Error\n\n");
				break;
		}
	}
	return 0;
}

node *insert(node *root,int ikey){//插入 
    node *tmp,*par,*ptr;
    ptr=root;
    par=NULL;
    
    int way[flag]={0};
    cal(way);
    flag++;
	int i;
	
    if(ptr!=NULL){
    	while(ptr->lthread==0){
	    	ptr=ptr->left;
		}
	    while(ptr!=NULL){
	        if(ikey==ptr->data){
	        	printf("already exit.\n");
	        	flag--;
	        	return root;
	        }
	        if(ptr->rthread==1)
	       		ptr=ptr->right;
	    	else{
	        	ptr=ptr->right;
	        	while(ptr->lthread==0){
	        		ptr=ptr->left;
				}
	    	}
	    }
	}
	
	ptr=root;
    for(i=0;way[i]!=0;i++){
        par=ptr;
        if(way[i]==0)//當way[i]==0時，跳出迴圈 
        	break;
        else if(way[i]==1)//當way[i]==1時，向左走 
            ptr=ptr->left;
        else if(way[i]==2)//當way[i]==2時，向右走 
            ptr=ptr->right;
    }
    i--;
    
    tmp=(node*)malloc(sizeof(node));
    tmp->data=ikey;
    tmp->lthread=1;
    tmp->rthread=1;
    
    if(par==NULL){
        root=tmp;
        tmp->left=NULL;
        tmp->right=NULL;
        return root;
	}
    else if(way[i]==1){
        tmp->left=par->left;
        tmp->right=par;
        par->lthread=0;
        par->left=tmp;
    }
    else{
   		tmp->left=par;
        tmp->right=par->right;
        par->rthread=0;
        par->right=tmp;
    }
    
    ptr=tmp;//heapsort
    par=ptr;
    while(i>-1){
    	if(way[i]==1){
   			if(par->rthread==1){
				par=par->right;
				if(ptr->data>par->data){
					int temp=ptr->data;
				    ptr->data=par->data;
				    par->data=temp;
				}
				if((par->left!=NULL)&&(par->right!=NULL)){
						if((par->lthread==0)&&(par->rthread==0)){
							if(par->right->data>par->left->data){
								int temp=par->right->data;
							    par->right->data=par->left->data;
						        par->left->data=temp;
							}
						}
					}
				ptr=par;
			}
			else{
				par=par->right;
				i++;
			}
		}
		else{
			if(par->lthread==1){
				par=par->left;
				if(ptr->data>par->data){
					int temp=ptr->data;
				    ptr->data=par->data;
				    par->data=temp;
				}
				if((par->left!=NULL)&&(par->right!=NULL)){
						if((par->lthread==0)&&(par->rthread==0)){
							if(par->right->data>par->left->data){
								int temp=par->right->data;
							    par->right->data=par->left->data;
						        par->left->data=temp;
							}
						}
					}
				ptr=par;
			}
			else{
				par=par->left;
				i++;
			}
		}
        i--;
	}
    
    return root;
}

node *del(node *root,int dkey){//刪除 
	
}

void cal(int way[]){//算出要怎麼走 
	int temp[flag]={0};
	int tmp=flag;
	int i;
	for(i=0;tmp>0;i++){
		temp[i]=(tmp%2)+1;
		tmp=tmp/2;
	}
	temp[i-1]=0;
	int k=0;
	for(int j=0;j<flag;j++){
		if(temp[flag-1-j]!=0){
			way[k]=temp[flag-1-j];
			k++;
		}
	}
}

void inorder(node *root){//中序輸出 
    node *ptr;
    if(root==NULL){
        printf("Tree is empty");
        return;
    }
	ptr=root;
    while(ptr->lthread==0){
    	ptr=ptr->left;
	}
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        if(ptr->rthread==1)
       		ptr=ptr->right;
    	else{
        	ptr=ptr->right;
        	while(ptr->lthread==0){
        		ptr=ptr->left;
			}
    	}
    }
}
