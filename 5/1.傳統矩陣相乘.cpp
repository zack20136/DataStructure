#include<stdio.h>
#include<stdlib.h>

struct Array{
	int row;
	int col;
	int value;
};

int main(){
	while(1){
		int m1=1,n1=1;
		printf("�п�J�x�}A(m*n)���j�p:");
		scanf("%d%d",&m1,&n1);
		if((m1==0)||(n1==0)){
			printf("�Э��s��J\n");
			continue;
		}
		int arr1[m1][n1];
		printf("�Ш̧ǿ�J�G���}�CA(%d*%d)���������e:\n",m1,n1);
		for(int i=0;i<m1;i++){
			for(int j=0;j<n1;j++){
				scanf("%d",&arr1[i][j]);
			}
		}
		
		int m2=1,n2=1;
		printf("�п�J�x�}B(m*n)���j�p:");
		scanf("%d%d",&m2,&n2);
		if((m2==0)||(n2==0)){
			printf("�Э��s��J\n");
			continue;
		}
		if(n1!=m2){
			printf("����ۭ�\n");
			continue;
		}
		int arr2[m2][n2];
		printf("�Ш̧ǿ�J�G���}�CA(%d*%d)���������e:\n",m2,n2);
		for(int i=0;i<m2;i++){
			for(int j=0;j<n2;j++){
				scanf("%d",&arr2[i][j]);
			}
		}
		
		int arr3[m1][n2];
		for (int i=0;i<m1;i++) {
        	for (int j=0;j<n2;j++) {
            	arr3[i][j]=0;
            	for(int k=0;k<n1;k++) {
                	arr3[i][j]=arr3[i][j]+arr1[i][k]*arr2[k][j];
            	}
        	}
    	}
		printf("�x�}�ۭ����G:\n");
		for(int i=0;i<m1;i++){
			for(int j=0;j<n2;j++){
				printf("%d ",arr3[i][j]);
			}
			printf("\n");
		}
		//2.�}���x�}
		int count=0;
		Array sum[m1*n2];
		for(int i=0;i<m1;i++){
			for(int j=0;j<n2;j++){
				if(arr3[i][j]!=0){
					sum[count].row=i;
					sum[count].col=j;
					sum[count].value=arr3[i][j];
					count++;
				}
			}
		}
		printf("�}���x�}:\n�ؤo: %d*%d ���ؼ�: %d\n",m1,n2,count);
		printf("index   row     col     value\n");
		for(int i=0;i<count;i++){
			printf("%d\t%d\t%d\t%d\n",i+1,sum[i].row,sum[i].col,sum[i].value);
		}
		//3.��m�x�}
		int arrT[n2][m1]={0};
		for(int i=0;i<count;i++){
			arrT[sum[i].col][sum[i].row]=sum[i].value;
		}
		
		printf("��m�x�}:\n�ؤo: %d*%d\n",n2,m1);
		for(int i=0;i<n2;i++){
			for(int j=0;j<m1;j++){
				printf("%d ",arrT[i][j]);
			}
			printf("\n");
		}
	}	
	return 0;
}
