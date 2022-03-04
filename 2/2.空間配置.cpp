#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	srand(time(NULL));
	char *s=(char*)malloc(sizeof(char)*20);
	for(int i=0;i<20;i++){
		s[i]=rand()%25+65;
	}
	
	printf("原始字母：\n");
	for(int i=0;i<20;i++){
		printf("%c ",s[i]);
	}
	printf("\n");
	
	for(int i=0;i<20;i++){
		for(int j=0;j<19;j++){
			if(s[j]>s[j+1]){
				char temp=s[j];
				s[j]=s[j+1];
				s[j+1]=temp;
			}
		}
	}
	
	printf("排序結果：\n");
	for(int i=0;i<20;i++){
		printf("%c ",s[i]);
	}
	
	return 0;
}
