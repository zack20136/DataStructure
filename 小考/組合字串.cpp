#include<stdio.h>
#include<stdlib.h>

void swap(char *a,char *b){
	char temp=*a;
	*a=*b;
	*b=temp;
}

void P(char *a, char *b){
	if(*b=='\0'){
		printf("%s\n",a);
	}
	else{
		for(char *c=b;*c!='\0';c++){
			swap(c,b);
			P(a,b+1);
			swap(c,b);
		}
	}
}

int main(){
	char str[6];
	printf("��J�r��:");
	scanf("%s",&str);
	
	int n=1,a=0;
	while(str[a]!='\0'){
		n=n*(a+1);
		a++;
	}
	printf("�r��%s��%d�زզX�r��:\n",str,n);
	
	P(str,str);
	
	return 0;
}
