#include<stdio.h>
#include<stdlib.h>
#define max 50

int cal(char *input){//�p��e�m�� 
	int num[max]={0};//�ΨӼȦs�Ʀr���}�C 
	int i;//�ΨӦsinput���ת��ܼ� 
	for(i=0;input[i]!='\0';i++){//�p��input���סA���K�N�Ȧs�Jnum�� 
		switch(input[i]){
			case '+': 
			case '-': 
        	case '*': 
			case '/': 
			case '%'://��J��+ - * / %�ɡA�N-9999�s�Jnum�� 
				num[i]=-9999;
				break;//���X 
        	default://��L�A�Ninput���Ȧs�Jnum�� 
				num[i]=input[i]-'0';
				break;//���X 
		}
	}
	//��J��s�b�@�_����ӼƭȮɡA�Ϋe�@�ӹB��l�h�p��
	//�M��N�p��X�Ӫ��Ȧs�J�o�ӭp��l����m�A�̫�N�}�C���e�������л\�B��L����ӼƦr 
	for(int j=0;j<i;j++){
		if((num[j]!=-9999)&&(num[j+1]!=-9999)){//��num[j]�Mnum[j+1]��������-9999�ɡA���� 
			switch(input[j-1]){
				case '+'://��J��+�ɡA�N��Ӽ�num[j] num[j+1]�ۥ[�æs�Jnum[j-1] 
					num[j-1]=num[j]+num[j+1];
					break;
				case '-'://��J��-�ɡA�N��Ӽ�num[j] num[j+1]��r��æs�Jnum[j-1]
					num[j-1]=num[j]-num[j+1];
					break;
        		case '*'://��J��*�ɡA�N��Ӽ�num[j] num[j+1]�ۭ��æs�Jnum[j-1]
					num[j-1]=num[j]*num[j+1];
					break;
				case '/'://��J��/�ɡA�N��Ӽ�num[j] num[j+1]�۰��æs�Jnum[j-1]
					num[j-1]=num[j]/num[j+1];
					break;
				case '%'://��J��%�ɡA�N��Ӽ�num[j] num[j+1]�Ҽƨæs�Jnum[j-1]
					num[j-1]=num[j]%num[j+1];
					break;
			}
			for(int k=j;k<i;k++){//�N�}�Cnum[j-1]�H�᪺�����e����� 
				input[k]=input[k+2];
				input[k+1]=input[k+3];
				num[k]=num[k+2];
				num[k+1]=num[k+3];
			}
			i-=2;//�Q��i�Mj�A�h���j�鰵��u�ѤUnum[0]���Ʀr���� 
			j=0;
		}
	}
	return num[0];//�^�Ǽƭ� 
}

int main(){
	while(1){
		char input[max]={'\0'};//�ΨӦs��J���}�C 
		int ans;//�ΨӦs���ת��ܼ� 
		printf("��J�n�p�⪺�e�m���]��J0�����^�G");
		scanf("%s",&input);//��J 
		if(input[0]=='0')//��input[0]����0�ɡA���� 
			if(input[1]=='\0')//��input[1]����'\0'�ɡA���� 
				break;//���X 
		ans=cal(input);//�I�s�p��e�m�����禡 
		printf("���סG%d\n",ans);//��X 
	}
	return 0;
}
