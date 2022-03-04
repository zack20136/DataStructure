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
        Node* pre;
        
        while(ptr!=NULL){
        	if(num==ptr->num){
        		printf("%d已經存在串列中",num);
            	return 0;
			}
        	pre=ptr;
            ptr=ptr->next;
		}
		
		ptr=head;
        if(ptr == NULL){
        	head=add;
        }
        else if(ptr->num<num){
        	pre=ptr;
        	head=add;
        	head->next=pre;
		}
        else{
        	int flag=0;
            while(ptr->next!=NULL){
            	pre=ptr;
            	ptr=ptr->next;
            	if(ptr->num<num){
            		pre->next=add;
					add->next=ptr;
            		flag=1;
            		break;
				}
			}
			if(flag==0){
				ptr->next=add;
			}
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
		printf("->%d",ptr->num);
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
