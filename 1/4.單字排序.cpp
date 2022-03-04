#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct str{
	char str1[20];
	str *next;
};

str *new_str(){
	str *newstr;
	newstr=(str*)malloc(sizeof(str));
	strcpy(newstr->str1,"");
	return newstr;
}

void lower(char a[]){
	int c=0;
	while(strncmp(a,"",1)!=0){
		c++;
		a++;
	}
	a-=c;
	for(int i=0;i<c;i++){
		if((a[i]>=65)&&(a[i]<=90)){
			a[i]=a[i]+32;
		}
	}
}

int main(){
	FILE *fp=fopen("input.txt","r");
	
	str *first=new_str();
	str *cur=first;
	str *newstr;
	str *pre;
	
	strcpy(cur->str1,"*");
	while(strncmp(cur->str1,"",1)!=0){
		newstr=new_str();
		pre=cur;
		cur->next=newstr;
		cur=cur->next;
		fscanf(fp,"%s",&cur->str1);
	}
	fclose(fp);
	
	cur=first->next;
	int count=0;
	while(cur->next!=NULL){
		count++;
		lower(cur->str1);
		cur=cur->next;
	}
	
	char temp[20];
	for(int i=0;i<count;i++){
		cur=first->next;
		for(int j=0;j<count-1;j++){
			pre=cur;
			cur=cur->next;
			if(strcmp(pre->str1,cur->str1)>0){
				strcpy(temp,pre->str1);
				strcpy(pre->str1,cur->str1);
				strcpy(cur->str1,temp);
			}
		}
	}
	
	fp=fopen("output.txt","w");
	cur=first->next;
	while(cur->next!=NULL){
		fprintf(fp,"%s\n",cur->str1);
		pre=cur;
		cur=cur->next;
	}
	fclose(fp);
	
	return 0;
}
