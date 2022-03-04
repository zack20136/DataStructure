#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	node *left;
	node *right;
	node *back;
};

int insert(node **pre,node **tree,int key){
	node *temp=NULL;
	if(!(*tree)){
		temp=(node*)malloc(sizeof(node));
		temp->data=key;
		temp->left=NULL;
		temp->right=NULL;
		temp->back=*pre;
		*tree = temp;
		return 0;
	}
	if(key==(*tree)->data){
		printf("%d already exist\n",key);
	}
	else if(key<(*tree)->data){
    	insert(&(*tree),&(*tree)->left,key);
	}
	else if(key>(*tree)->data){
    	insert(&(*tree),&(*tree)->right, key);
	}
}

int del(node **tree,int key,int flag){
	node *ptr=(*tree);
	if((*tree)!=NULL){
		if(key>(*tree)->data){
			del(&(*tree)->right,key,1);
		}
		else if(key<(*tree)->data){
			del(&(*tree)->left,key,2);
		}
		else if(key==(*tree)->data){
			if(flag==0){
				if(ptr->left){
					(*tree)=ptr->left;
					if(ptr->right){
						(*tree)->left=ptr->right;
					}
					free(ptr);
				}
				else if(ptr->right){
					(*tree)=ptr->right;
					if(ptr->left){
						(*tree)->right=ptr->left;
					}
					free(ptr);
				}
				else{
					(*tree)=NULL;
					free(ptr);
				}
			}
			else if(flag==1){
				if(ptr->left){
					ptr=ptr->left;
					while(ptr->right!=NULL){
						ptr=ptr->right;
					}
					(*tree)->data=ptr->data;
					if(ptr->left){
						ptr->back->right=ptr->left;
						ptr->left->back=ptr->back;
					}
					else{
						ptr->back->right=NULL;
					}
					free(ptr);
				}
				else if(ptr->right){
					ptr->back->right=ptr->right;
					ptr->right->back=ptr->back;
					free(ptr);
				}
				else{
					ptr->back->right=NULL;
					free(ptr);
				}
			}
			else if(flag==2){
				if(ptr->right){
					ptr=ptr->right;
					while(ptr->left!=NULL){
						ptr=ptr->left;
					}
					(*tree)->data=ptr->data;
					if(ptr->right){
						ptr->back->left=ptr->right;
						ptr->right->back=ptr->back;
					}
					else{
						ptr->back->left=NULL;
					}
					free(ptr);
				}
				else if(ptr->left){
					ptr->back->left=ptr->left;
					ptr->left->back=ptr->back;
					free(ptr);
				}
				else{
					ptr->back->left=NULL;
					free(ptr);
				}
			}
			return 0;
		}
	}
	else{
		printf("does not exist in the tree.\n");
		return 0;
	}
}

void preorder(node*tree){
	if(tree){
		printf("%d ",tree->data);
		preorder(tree->left);
		preorder(tree->right);
	}
}

int main(){
	node *root=NULL;

	while(1){
		int input=1;
		printf("[1] Add [2] Delete [0] Exit:");
		scanf("%d",&input);
		switch(input){
			case 0:
				printf("Exit");
				return 0;
			case 1:
				printf("Insert a number :");
				scanf("%d",&input);
				insert(&root,&root,input);
				preorder(root);
				printf("\n");
				break;
			case 2:
				printf("Delete a number :");
				scanf("%d",&input);
				del(&root,input,0);
				preorder(root);
				printf("\n");
				break;
			default:
				printf("Error input\n");
				break;
		}
	}
	
}

