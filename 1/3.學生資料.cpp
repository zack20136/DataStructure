#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct student{
	char name[5]={0};
	int s1;
	int s2;
	int avg;
	int grade;
};

student stu1[26],stu2[26],temp;

void f1(){
	char a;
	a=rand()%25+65;
	for(int i=0;i<25;i++){
		a++;
		if(a>90){
			a=65;
		}
		stu1[i].name[0]=a;
		stu1[i].name[1]=a;
		stu1[i].name[2]=a;
		stu1[i].s1=rand()%60+40;
		stu1[i].s2=rand()%60+40;
	}
}

void f2(){
	printf("�m�W\t�p�����Z\t�L�n�����Z\n");
	for(int i=0;i<25;i++){
		printf("%s\t%d\t\t%d\n",stu1[i].name,stu1[i].s1,stu1[i].s2);
	}
}

void f3(){
	for(int i=0;i<25;i++){
		stu2[i]=stu1[i];
		stu2[i].avg=(stu2[i].s1+stu2[i].s2)/2;
	}
	for(int i=0;i<25;i++){
		for(int j=0;j<24;j++){
			if(stu2[j].avg<stu2[j+1].avg){
				temp=stu2[j];
				stu2[j]=stu2[j+1];
				stu2[j+1]=temp;
			}
			else if((stu2[j].avg==stu2[j+1].avg)&&(stu2[j].s1<stu2[j+1].s1)){
				temp=stu2[j];
				stu2[j]=stu2[j+1];
				stu2[j+1]=temp;
			}
			else if((stu2[j].avg==stu2[j+1].avg)&&(stu2[j].s1==stu2[j+1].s1)&&(stu2[j].s2<stu2[j+1].s2)){
				temp=stu2[j];
				stu2[j]=stu2[j+1];
				stu2[j+1]=temp;
			}
		}
	}
	for(int i=0;i<25;i++){
		stu2[i].grade=i+1;
	}
	printf("�m�W\t�p�����Z\t�L�n�����Z\t����\t�ƦW\n");
	for(int i=0;i<25;i++){
		printf("%s\t%d\t\t%d\t\t%d\t%d\n",stu2[i].name,stu2[i].s1,stu2[i].s2,stu2[i].avg,stu2[i].grade);
	}
}

int main(){
	srand(time(NULL));
	int input=0,flag=0;
	while(input!=4){
		printf("\n(1) ��l��Ʋ���\n(2) �C�L��l���\n(3) �C�L�ƧǦ��Z\n(4) �����{������\n�G");
		scanf("%d",&input);
		if(input==1){
			flag=1;
			f1(); 
		}
		else if((flag==1)&&(input==2)){
			f2();
		}
		else if((flag==1)&&(input==3)){
			f3();
		}
		else if(input==4){
			printf("����\n");
			break;
		}
		else{
			printf("��J���~�Υ�����(1)\n");
		}
	}
	return 0;
}
