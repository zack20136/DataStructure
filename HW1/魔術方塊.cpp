#include<stdio.h>
#include<stdlib.h>
int flag=1;//�p��O�_���즳�ƭȮ�l���ܼ� 
int generate(int square[],int size,int count,int max){//�����U 
	if(max<=2){//���X���j������ 
		return square[count]=size*size+1;
	}
	count=count-size-1;//�����W���ʤ@�� 
	if(count<0){//���W�S����l�ɡA���^�̤U������ 
		count=count+size*size;
	}
	if(flag==size){//���즳�ƭȪ���l�ɡA���U���ʤ@�� 
		flag=0;
		count=count+size*2+1;
	}
	else if((count+1)%size==0){//��V�W����ɡA���U���ʤ@�� 
		count=count+size;
	}
	if(count>size*size){//��k�U��l�ɡA����̤W������ 
		count=count-size*size;
	}
	flag++;
	return square[count]=generate(square,size,count,max-1)-1;
}
int main(){
	int size=0;
	printf("Enter the size of the square:");
	scanf("%d",&size);
	if((size<1)||(size%2==0)){//���� 
		printf("Error");
		exit(1);
	}
	int square[size*size]={0};
	int count=(size-1)/2;//�]�w�_�l��l 
	int max=size*size+1;//�ƭȳ̤j�� 
	
	square[count]=generate(square,size,count,max)-1;//�I�s��� 
	
	for(int i=0;i<size*size;i++){//�L�X 
		printf("%3d ",square[i]);	
		if((i+1)%size==0){
			printf("\n");
		}
	} 
	return 0;
}
