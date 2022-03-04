#include<stdio.h>
#include<stdlib.h>

struct Node{
        int num;
        struct Node *next;
};
Node* head = NULL; 

Node* newNode(int num){
    Node* add=(Node*)malloc(sizeof(Node));  
    add->num = num;
    add->next = NULL;
    return add;
}

int Insert(){
        int num;
        printf("Insert a number: ");
        scanf("%d",&num);
        Node* add = newNode(num);
        Node* ptr = head;
        if(ptr == NULL){
        	head=add;
        } 
        else{
            while(ptr->next!=NULL){
            	ptr=ptr->next;
			}
			ptr->next=add;
        }
        return 0;
    }

int Delete(){
    int num;
    printf("Delete a number: ");
    scanf(" %d",&num);
    Node* ptr = head;
    Node* del = NULL;
    if(ptr == NULL){
        printf("Not in the list!\n");
        return 0;
    }
    int flag=0;
    del=ptr;
    ptr=ptr->next;
    while(ptr != NULL){
        if(ptr->num == num){
			del->next=ptr->next;
        	ptr=del->next;
			flag=1;
		}
		else{
			del=ptr;
        	ptr=ptr->next;
		}
    }
    ptr=head;
    if(ptr->num == num){
        head=head->next;
        flag=1;
	}
    if(flag==0){
    	printf("Not in the list!\n");
	}
    return 0;
}

int Show(){
	Node* ptr = head;
	printf("%d",ptr->num);
	ptr=ptr->next;
	while(ptr!=NULL){
		printf(" -> %d",ptr->num);
		ptr=ptr->next;
	}
	printf("\n");
	return 0;
}

int main(void){
	int input;
	while(1){
		printf("  操作選項表\n==============\n[1]加入資料\n[2]刪除資料\n[3]列印\n[4]結束\n");
		printf("輸入選項:");
		scanf("%d",&input);
		switch(input){
			case 1:
				Insert();
				break;
			case 2:
				Delete();
				break;
			case 3:
				Show();
				break;
			case 4:
				return 0;
			default:
				printf("ERROR!!!!\n");	
		}
	}
}
