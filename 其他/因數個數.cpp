#include<stdio.h>
#include<stdlib.h>

int main(){
	while(1){
		int n;
		int temp[100]={0};
		printf("��J��ơG");
		scanf("%d",&n);
		if(n==0)
			break;
			
		int i=2;
		int j=0;
		while(n>1){
			int flag=0;
			while(n%i==0){
				n=n/i;
				temp[j]+=1;
				flag=1;
			}
			if(flag==1){
				j++;
			}
			i++;
		}
		
		int ans=1;
		for(int k=0;k<j;k++){
			ans=ans*(temp[k]+1);
		}
		printf("�]�Ʀ��G%d��\n",ans);
	}
	return 0;
}
