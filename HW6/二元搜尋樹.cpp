#include<stdio.h>
#include<stdlib.h>

struct node{//�𪺸`�I 
	int data;
	node *left;
	node *right;
	node *back;
};

int insert(node **pre,node **tree,int key){//���J 
	node *temp=NULL;//�Ȧs�ܼ� 
	if(!(*tree)){//��(*tree)=NULL�ɡA�ͦ��@�ӷs���`�I�A�èϨ�data=key 
		temp=(node*)malloc(sizeof(node));
		temp->data=key;
		temp->left=NULL;
		temp->right=NULL;
		temp->back=*pre;
		*tree = temp;
		return 0;
	}
	if(key==(*tree)->data){//��(*tree)��data=key�ɡA�L�X�o�ӼƦr�w�s�b 
		printf("%d already exist\n",key);
	}
	else if(key<(*tree)->data){//��(*tree)��data>key�ɡA�A���I�s�ۤv�A�V�k�l�� 
    	insert(&(*tree),&(*tree)->left,key);
	}
	else if(key>(*tree)->data){//��(*tree)��data<key�ɡA�A���I�s�ۤv�A�V���l��
    	insert(&(*tree),&(*tree)->right, key);
	}
}

int del(node **tree,int key,int flag){//�R�� 
	node *ptr=(*tree);//�Ȧs�ثe��l�������ܼ� 
	if((*tree)!=NULL){//��(*tree)!=NULL�ɡA���� 
		if(key>(*tree)->data){//��(*tree)��data<key�ɡA�A���I�s�ۤv�A�V�k�l�� 
			del(&(*tree)->right,key,1);
		}
		else if(key<(*tree)->data){//��(*tree)��data<key�ɡA�A���I�s�ۤv�A�V���l��
			del(&(*tree)->left,key,2);
		}
		else if(key==(*tree)->data){//��(*tree)��data=key�ɡA�h�P�_�n�R�����`�I�O�������� 
			if(flag==0){//��n�R�����O�ڸ`�I�� 
				if(ptr->left){//ptr�����l�𦳪F��� 
					(*tree)=ptr->left;//�ξ𪺥��l����N�� 
					if(ptr->right){//�p�G�𪺥k�l�𦳪F��A�N�𪺥��l�𪺥k�l��=�𪺥k�l�� 
						(*tree)->left=ptr->right;
					}
					free(ptr);
				}
				else if(ptr->right){//ptr�����l��S�F��A���k�l�Ʀ��F���
					(*tree)=ptr->right;//�ξ𪺥k�l����N�� 
					if(ptr->left){//�p�G�𪺥��l�𦳪F��A�N�𪺥k�l�𪺥��l��=�𪺥��l�� 
						(*tree)->right=ptr->left;
					}
					free(ptr);
				}
				else{//ptr�����B�k�l�𳣨S�F���
					(*tree)=NULL;//�����N�o�Ӹ`�I�R�� 
					free(ptr);
				}
			}
			else if(flag==1){//��n�R�����O���`�I��
				if(ptr->left){//ptr�����l�𦳪F���
					ptr=ptr->left;//���Nptr=ptr�����l�� 
					while(ptr->right!=NULL){//�@�����k���A���쨫��̫�@�� 
						ptr=ptr->right;
					}
					(*tree)->data=ptr->data;//�Ψ��쪺����l��data���N���l��data 
					if(ptr->left){//�p�G���쪺�𪺥��l�𦳪F��A�N�𪺥k�l�𪺥��l��=�𪺥��l�� 
						ptr->back->right=ptr->left;
						ptr->left->back=ptr->back;
					}
					else{//�p�G�S���A�����N�o�Ӹ`�I�R�� 
						ptr->back->right=NULL;
					}
					free(ptr);
				}
				else if(ptr->right){//ptr�����l��S�F��A���k�l�Ʀ��F���
					ptr->back->right=ptr->right;//�����Nptr=ptr���k�l�� 
					ptr->right->back=ptr->back;
					free(ptr);
				}
				else{//ptr�����B�k�l�𳣨S�F���
					ptr->back->right=NULL;//�����Nptr�R�� 
					free(ptr);
				}
			}
			else if(flag==2){//��n�R�����O�k�`�I�� 
				if(ptr->right){//ptr���k�l�𦳪F���
					ptr=ptr->right;//���Nptr=ptr���k�l�� 
					while(ptr->left!=NULL){//�@���������A���쨫��̫�@�� 
						ptr=ptr->left;
					}
					(*tree)->data=ptr->data;//�Ψ��쪺����l��data���N���l��data 
					if(ptr->right){//�p�G���쪺�𪺥k�l�𦳪F��A�N�𪺥��l�𪺥k�l��=�𪺥k�l�� 
						ptr->back->left=ptr->right;
						ptr->right->back=ptr->back;
					}
					else{//�p�G�S���A�����N�o�Ӹ`�I�R�� 
						ptr->back->left=NULL;
					}
					free(ptr);
				}
				else if(ptr->left){//ptr���k�l��S�F��A�����l�Ʀ��F���
					ptr->back->left=ptr->left;//�����Nptr=ptr�����l��
					ptr->left->back=ptr->back;
					free(ptr);
				}
				else{//ptr�����B�k�l�𳣨S�F���
					ptr->back->left=NULL;//�����Nptr�R�� 
					free(ptr);
				}
			}
			return 0;
		}
	}
	else{//��key!=�Ҧ�(*tree)��data�ɡA�L�X�A�ø��X�j�� 
		printf("does not exist in the tree.\n");
		return 0;
	}
}

void preorder(node*tree){//�e�ǿ�X 
	if(tree){
		printf("%d ",tree->data);
		preorder(tree->left);
		preorder(tree->right);
	}
}

int main(){
	node *root=NULL;//�ڸ`�I 

	while(1){
		int input=1;
		printf("[1] Add [2] Delete [0] Exit:");
		scanf("%d",&input);
		switch(input){
			case 0://��input=0�ɡA�L�XEXIT�A�ø��X�{�� 
				printf("EXIT");
				return 0;
			case 1://��input=1�ɡA���J1�ӼƦr 
				printf("Insert a number :");
				scanf("%d",&input);
				insert(&root,&root,input);
				printf("preorder: ");
				preorder(root);
				printf("\n");
				break;
			case 2://��input=0�ɡA�R���@�ӼƦr 
				printf("Delete a number :");
				scanf("%d",&input);
				del(&root,input,0);
				printf("preorder: ");
				preorder(root);
				printf("\n");
				break;
			default://���J���~�ɡA�LError 
				printf("Error input\n");
				break;
		}
	}
}

