#include<stdio.h>
#include<stdlib.h>

struct node{//樹的節點 
	int data;
	node *left;
	node *right;
	node *back;
};

int insert(node **pre,node **tree,int key){//插入 
	node *temp=NULL;//暫存變數 
	if(!(*tree)){//當(*tree)=NULL時，生成一個新的節點，並使其data=key 
		temp=(node*)malloc(sizeof(node));
		temp->data=key;
		temp->left=NULL;
		temp->right=NULL;
		temp->back=*pre;
		*tree = temp;
		return 0;
	}
	if(key==(*tree)->data){//當(*tree)的data=key時，印出這個數字已存在 
		printf("%d already exist\n",key);
	}
	else if(key<(*tree)->data){//當(*tree)的data>key時，再次呼叫自己，向右子樹走 
    	insert(&(*tree),&(*tree)->left,key);
	}
	else if(key>(*tree)->data){//當(*tree)的data<key時，再次呼叫自己，向左子樹走
    	insert(&(*tree),&(*tree)->right, key);
	}
}

int del(node **tree,int key,int flag){//刪除 
	node *ptr=(*tree);//暫存目前位子的指標變數 
	if((*tree)!=NULL){//當(*tree)!=NULL時，執行 
		if(key>(*tree)->data){//當(*tree)的data<key時，再次呼叫自己，向右子樹走 
			del(&(*tree)->right,key,1);
		}
		else if(key<(*tree)->data){//當(*tree)的data<key時，再次呼叫自己，向左子樹走
			del(&(*tree)->left,key,2);
		}
		else if(key==(*tree)->data){//當(*tree)的data=key時，去判斷要刪除的節點是哪種類型 
			if(flag==0){//當要刪除的是根節點時 
				if(ptr->left){//ptr的左子樹有東西時 
					(*tree)=ptr->left;//用樹的左子樹取代它 
					if(ptr->right){//如果樹的右子樹有東西，將樹的左子樹的右子樹=樹的右子樹 
						(*tree)->left=ptr->right;
					}
					free(ptr);
				}
				else if(ptr->right){//ptr的左子樹沒東西，但右子數有東西時
					(*tree)=ptr->right;//用樹的右子樹取代它 
					if(ptr->left){//如果樹的左子樹有東西，將樹的右子樹的左子樹=樹的左子樹 
						(*tree)->right=ptr->left;
					}
					free(ptr);
				}
				else{//ptr的左、右子樹都沒東西時
					(*tree)=NULL;//直接將這個節點刪除 
					free(ptr);
				}
			}
			else if(flag==1){//當要刪除的是左節點時
				if(ptr->left){//ptr的左子樹有東西時
					ptr=ptr->left;//先將ptr=ptr的左子樹 
					while(ptr->right!=NULL){//一直往右走，直到走到最後一個 
						ptr=ptr->right;
					}
					(*tree)->data=ptr->data;//用走到的的位子的data取代原位子的data 
					if(ptr->left){//如果走到的樹的左子樹有東西，將樹的右子樹的左子樹=樹的左子樹 
						ptr->back->right=ptr->left;
						ptr->left->back=ptr->back;
					}
					else{//如果沒有，直接將這個節點刪除 
						ptr->back->right=NULL;
					}
					free(ptr);
				}
				else if(ptr->right){//ptr的左子樹沒東西，但右子數有東西時
					ptr->back->right=ptr->right;//直接將ptr=ptr的右子樹 
					ptr->right->back=ptr->back;
					free(ptr);
				}
				else{//ptr的左、右子樹都沒東西時
					ptr->back->right=NULL;//直接將ptr刪除 
					free(ptr);
				}
			}
			else if(flag==2){//當要刪除的是右節點時 
				if(ptr->right){//ptr的右子樹有東西時
					ptr=ptr->right;//先將ptr=ptr的右子樹 
					while(ptr->left!=NULL){//一直往左走，直到走到最後一個 
						ptr=ptr->left;
					}
					(*tree)->data=ptr->data;//用走到的的位子的data取代原位子的data 
					if(ptr->right){//如果走到的樹的右子樹有東西，將樹的左子樹的右子樹=樹的右子樹 
						ptr->back->left=ptr->right;
						ptr->right->back=ptr->back;
					}
					else{//如果沒有，直接將這個節點刪除 
						ptr->back->left=NULL;
					}
					free(ptr);
				}
				else if(ptr->left){//ptr的右子樹沒東西，但左子數有東西時
					ptr->back->left=ptr->left;//直接將ptr=ptr的左子樹
					ptr->left->back=ptr->back;
					free(ptr);
				}
				else{//ptr的左、右子樹都沒東西時
					ptr->back->left=NULL;//直接將ptr刪除 
					free(ptr);
				}
			}
			return 0;
		}
	}
	else{//當key!=所有(*tree)的data時，印出，並跳出迴圈 
		printf("does not exist in the tree.\n");
		return 0;
	}
}

void preorder(node*tree){//前序輸出 
	if(tree){
		printf("%d ",tree->data);
		preorder(tree->left);
		preorder(tree->right);
	}
}

int main(){
	node *root=NULL;//根節點 

	while(1){
		int input=1;
		printf("[1] Add [2] Delete [0] Exit:");
		scanf("%d",&input);
		switch(input){
			case 0://當input=0時，印出EXIT，並跳出程式 
				printf("EXIT");
				return 0;
			case 1://當input=1時，插入1個數字 
				printf("Insert a number :");
				scanf("%d",&input);
				insert(&root,&root,input);
				printf("preorder: ");
				preorder(root);
				printf("\n");
				break;
			case 2://當input=0時，刪除一個數字 
				printf("Delete a number :");
				scanf("%d",&input);
				del(&root,input,0);
				printf("preorder: ");
				preorder(root);
				printf("\n");
				break;
			default://當輸入錯誤時，印Error 
				printf("Error input\n");
				break;
		}
	}
}

