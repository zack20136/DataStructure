#include<stdio.h>
#include<stdlib.h>

struct Array{
	int num;
	int exp;
};

int add(Array *arr,int k,int n){//�N���趵�@�˪��[�_�� 
	for(int i=k;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i].exp==arr[j].exp){//����۵��A�N�ⶵ�Y�Ƭۥ[ 
				arr[i].num+=arr[j].num;
				while(arr[j+1].num!=0){//�Ϋ�@�Ӽƨ��N�Q�ۥ[���ƪ���m 
					arr[j]=arr[j+1];
					j++;
				}
				arr[j].num=0;//�N�h�X�Ӫ���m�k�s 
				arr[j].exp=0;
				n--;//�N������m�V�e����1 
				i--;
			}
		}
	}
	return n;
}

void sort(Array *arr,int k,int n){//�N���趵�q�j�ƨ�p
	for(int i=k;i<n;i++){ 
		for(int j=i+1;j<n;j++){
			if(arr[i].exp<arr[j].exp){//��e������p��ᶵ�ɡA�N�ⶵ�洫��m 
				Array temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
}

int main(){
	Array arr[200]={0};
	int s1,s2,f1,f2;//�s���h�����}�Y�M�������ܼ� 
	int n=0;//�B��l 
	
	//�h����1 
	s1=n;//�]�w�h����1�}�Y��m 
	while(1){
		int in1,in2;
		printf("�h����1�]�Y�� ����^�G");
		scanf("%d %d",&in1,&in2);
		if((in1==0)&&(in2==0))//���O0�ɡA���X�j�� 
			break;
		if(in1==0)//��Y�ƬO0�ɡA�������������ʧ@ 
			continue;
		arr[n].num=in1;
		arr[n].exp=in2;
		n++;
	}
	f1=n;//�]�w�h����1������m
	n=add(arr,s1,f1);//�⦸��@�˪����ۥ[ 
	sort(arr,s1,f1);//�q����j�ƨ�p 
	f1=n;//�]�w�h����1������m
	printf("�h����1�G");//�L�X�h����1
	for(int i=s1;i<f1;i++){
		printf("%dx^%d ",arr[i].num,arr[i].exp);
		if(i==f1-1)
			break;
		printf(" + ");
	}
	printf("\n\n");
	
	n++;
	//�h����2
	s2=n;//�]�w�h����2�}�Y��m
	while(1){
		int in1,in2;
		printf("�h����2�]�Y�� ����^�G");
		scanf("%d %d",&in1,&in2);
		if((in1==0)&&(in2==0))//���O0�ɡA���X�j�� 
			break;
		if(in1==0)//��Y�ƬO0�ɡA�������������ʧ@
			continue;
		arr[n].num=in1;
		arr[n].exp=in2;
		n++;
	}
	f2=n;//�]�w�h����2������m
	n=add(arr,s2,f2);//�⦸��@�˪����ۥ[ 
	sort(arr,s2,f2);//�q����j�ƨ�p 
	f2=n;//�]�w�h����2������m
	printf("�h����2�G");//�L�X�h����2 
	for(int i=s2;i<f2;i++){
		printf("%dx^%d ",arr[i].num,arr[i].exp);
		if(i==f2-1)
			break;
		printf(" + ");
	}
	printf("\n\n");
	
	n++;
	int k=n;//�ۭ� 
	for(int i=s1;i<f1;i++){
		for(int j=s2;j<f2;j++){
			arr[n].num=arr[i].num*arr[j].num;
			arr[n].exp=arr[i].exp*arr[j].exp;
			n++;
		}
	}
	
	n=add(arr,k,n);//�⦸��@�˪����ۥ[ 
	sort(arr,k,n);//�q����j�ƨ�p 
	while(1){//�L�X 
		printf("%dx^%d",arr[k].num,arr[k].exp);
		k++;
		if(arr[k].num==0)
			break;
		printf(" + ");
	}
	
	return 0;
}
