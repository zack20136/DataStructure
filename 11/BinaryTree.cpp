#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	node *left;
	node *right;
};

int insert(node **tree,int key){
	node *temp=NULL;
	if(!(*tree)){
		temp=(node*)malloc(sizeof(node));
		temp->data=key;
		temp->left=NULL;
		temp->right=NULL;
		*tree = temp;
		return 0;
	}
	if(key==(*tree)->data){
		printf("%d already exist\n",key);
	}
	else if(key<(*tree)->data){
    	insert(&(*tree)->left,key);
	}
	else if(key>(*tree)->data){
    	insert(&(*tree)->right, key);
	}
}

void preorder(node*tree){
	if(tree){
		printf("%d ",tree->data);
		preorder(tree->left);
		preorder(tree->right);
	}
}

void posorder(node*tree){
	if(tree){
		posorder(tree->left);
		posorder(tree->right);
		printf("%d ",tree->data);
	}
}

void inorder(node *tree){
	if(tree){
		inorder(tree->left);
		printf("%d ",tree->data);
		inorder(tree->right);
	}
}

int max(node *tree){
	while(tree->right != NULL){
		tree=tree->right;
	}
	return tree->data;
}

int min(node *tree){
	while(tree->left != NULL){
		tree=tree->left;
	}
	return tree->data;
}

void leafnodes(node*tree){
	if(tree){
		if((tree->left==NULL)&&(tree->right==NULL))
			printf("%d ",tree->data);
		leafnodes(tree->left);
		leafnodes(tree->right);
	}
}

int main(){
	node *root=NULL;
	int input=1;
	
	while(1){
		printf("Insert a number :");
		scanf("%d",&input);
		if(input==0)
			break;
		insert(&root,input);
	}
	
	printf("Preorder : ");
	preorder(root);
	printf("\n");
	
	printf("Inorder : ");
	inorder(root);
	printf("\n");
	
	printf("Postorder : ");
	posorder(root);
	printf("\n");
	
	printf("MAX : %d",max(root));
	printf("\n");
	
	printf("MIN : %d",min(root));
	printf("\n");
	
	printf("LeafNodes :");
	leafnodes(root);
	printf("\n");
	
	return 0;
}

