#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 50000//����̦h���ʴX�� 

int move(int *arr,int *p1,int *p2,int n,int m){
	int flag=0;//�ΨӧP�_�������ʬO�_���\���ܼ� 
	int x=*p1,y=*p2;//��x,y�ȮɱNp1,p2���Ȧs�_�� 
	switch(rand()%8){//���ͬ�0��7���ü� 
		case 0://�V�k�� 
			y++;
			if(y>m){//��W�X��ɡA���������欰 
				flag=1;
			}
			break;
		case 1://�V�k�U��
			x++;
			y++;
			if((x>n)||(y>m)){//��W�X��ɡA���������欰
				flag=1;
			}
			break;
		case 2://�V�U�� 
			x++;
			if(x>n){//��W�X��ɡA���������欰
				flag=1;
			}
			break;
		case 3://�V���U�� 
			x++;
			y--;
			if((x>n)||(y<1)){//��W�X��ɡA���������欰
				flag=1;
			}
			break;
		case 4://�V���� 
			y--;
			if(y<1){//��W�X��ɡA���������欰
				flag=1;
			}
			break;
		case 5://�V���W�� 
			x--;
			y--;
			if((x<1)||(y<1)){//��W�X��ɡA���������欰
				flag=1;
			}
			break;
		case 6://�V�W�� 
			x--;
			if(x<1){//��W�X��ɡA���������欰
				flag=1;
			}
			break;
		case 7://�V�k�W�� 
			x--;
			y++;
			if((x<1)||(y>m)){//��W�X��ɡA���������欰
				flag=1;
			}
			break; 
	}
	if(flag==0){//��flag=0�A��count[x][y]�[�@�A�åB�Nx,y�s�^p1,p2�A�̫�^��0 
		arr[x*m-(m-y)-1]++;
		*p1=x;
		*p2=y;
		return 0;
	}
	else{//�p�Gflag!=0�A�^��1 
		return 1;
	}
}

int check(int *arr,int num){//�ˬd�O�_�C�Ӯ�l�����L�@���F 
	for(int i=0;i<num;i++){
		if(arr[i]==0){//�p�G�}�C�̦��@�ӵ���0���N���X�A�^�ǹs 
			return 0;
		}
	}
	return 1;//������}�C�����O0�A�^��0 
}

int main(){
	srand(time(NULL));
	int n=15,m=15;//�j�p 
	int p1=10,p2=10;//�_�l��m 
	printf("�j�p(n*m)�G");
	scanf("%d%d",&n,&m);
	printf("�_�l��m(x,y)�G");
	scanf("%d%d",&p1,&p2);
	int count[n][m];//�p����樫�L�X�����}�C 
	for(int i=0;i<n;i++){//�N�}�C��l�� 
		for(int j=0;j<m;j++){
			count[i][j]=0;
		}
	}
	
	for(int i=0;i<MAX;i++){//�b�W�w�����ƥH���A���䲾�� 
		i-=move(*count,&p1,&p2,n,m);//�I�s�禡 
		if(check(*count,n*m)==1){//���ˬd�L�F�A���X�j�� 
			printf("����%d�B�ɡA�C�泣���L1��\n\n",i+1);
			break;
		}
	}
	
	int k=0;//�ƪ� 
	for(int i=0;i<n;i++){//�L�X���樫��L�X�� 
		for(int j=0;j<m;j++){
			printf("(%2d,%2d)�G%5d��  ",i+1,j+1,count[i][j]);
			k++;//�ƪ� 
			if(k>2){//�ƪ� 
				printf("\n");
				k=0;
			}
		}
	}
	return 0;
}
