#include<stdio.h>
#include<stdlib.h>

struct Array{
	int num;
	int exp;
};

int main(){
	//�h����1
	int n=0;
	Array arr[100]={0};
	while(1){
		int in1,in2;
		printf("��J�h����1(�Y�� ����):");
		scanf("%d%d",&in1,&in2);
		if((in1==0)&&(in2==0))
			break;
		arr[n].num=in1;
		arr[n].exp=in2;
		n++;
	}
	int c=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i].exp==arr[j].exp){
				arr[i].num+=arr[j].num;
				arr[j].num=0;
				arr[j].exp=0;
				c++;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i].num==0){
				arr[i].exp=0;
				c++;
				break;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			if(arr[j].exp<arr[j+1].exp){
				Array temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	n-=c;
	for(int i=n;i>=0;i--){
		if(arr[i].num==0){
			n--;
		}
	}
	printf("--�h����1��:");
	for(int i=0;i<n;i++){
		printf("%dx^%d + ",arr[i].num,arr[i].exp);
	}
	printf("%dx^%d\n\n",arr[n].num,arr[n].exp);
	
	//�h����2
	n++;
	int nn=n;
	while(1){
		int in1,in2;
		printf("��J�h����2(�Y�� ����):");
		scanf("%d%d",&in1,&in2);
		if((in1==0)&&(in2==0))
			break;
		arr[n].num=in1;
		arr[n].exp=in2;
		n++;
	}
	c=0;
	for(int i=nn;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i].exp==arr[j].exp){
				arr[i].num+=arr[j].num;
				arr[j].num=0;
				arr[j].exp=0;
				c++;
			}
		}
	}
	for(int i=nn;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i].num==0){
				arr[i].exp=0;
				c++;
				break;
			}
		}
	}
	for(int i=nn;i<n;i++){
		for(int j=nn;j<n-1;j++){
			if(arr[j].exp<arr[j+1].exp){
				Array temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	n-=c;
	for(int i=n;i>=nn;i--){
		if(arr[i].num==0){
			n--;
		}
	}
	printf("--�h����2��:");
	for(int i=nn;i<n;i++){
		printf("%dx^%d + ",arr[i].num,arr[i].exp);
	}
	printf("%dx^%d\n\n",arr[n].num,arr[n].exp);
	
	//�ۥ[���G
	n++;
	c=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i].num==0){
				break;
			}
			if(arr[i].exp==arr[j].exp){
				arr[i].num+=arr[j].num;
				arr[j].num=0;
				arr[j].exp=0;
				c++;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			if(arr[j].exp<arr[j+1].exp){
				Array temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
			if(arr[j].num==0&&arr[j+1].num!=0){
				Array temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	n-=c;
	for(int i=n;i>=0;i--){
		if(arr[i].num==0){
			n--;
		}
	}
	printf("�ۥ[���G��:");
	int i=0;
	while(arr[i].num!=0){
		if(i==0){
			printf("%dx^%d",arr[i].num,arr[i].exp);
		}
		else{
			printf(" + %dx^%d",arr[i].num,arr[i].exp);
		}
		i++;
	}
	
	return 0;
} 
