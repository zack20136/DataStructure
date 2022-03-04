#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct student{
	char name[20]={0};
	int num;
	int s1;
	int s2;
	int avg;
	int grade;
};

int main(){
	srand(time(NULL));
	student stu[51],temp;
	FILE *fp=fopen("name.txt","r");
	char str[20];
	for(int i=0;i<50;i++){
		fscanf(fp,"%s",&stu[i].name);
		stu[i].num=i+1;
		stu[i].s1=rand()%70+30;
		stu[i].s2=rand()%70+30;
	}
	fclose(fp);
	
	fp=fopen("student.txt","w");
	fprintf(fp,"姓名\t\t號碼\n---------------------\n");
	for(int i=0;i<50;i++){
		fprintf(fp,"%11s\t%d\n\n",stu[i].name,stu[i].num);
	}
	
	for(int i=0;i<50;i++){
		stu[i].avg=(stu[i].s1+stu[i].s2)/2;
	}
	for(int i=0;i<50;i++){
		for(int j=0;j<49;j++){
			if(stu[j].avg<stu[j+1].avg){
				temp=stu[j];
				stu[j]=stu[j+1];
				stu[j+1]=temp;
			}
			else if((stu[j].avg==stu[j+1].avg)&&(stu[j].s1<stu[j+1].s1)){
				temp=stu[j];
				stu[j]=stu[j+1];
				stu[j+1]=temp;
			}
			else if((stu[j].avg==stu[j+1].avg)&&(stu[j].s1==stu[j+1].s1)&&(stu[j].s2<stu[j+1].s2)){
				temp=stu[j];
				stu[j]=stu[j+1];
				stu[j+1]=temp;
			}
		}
	}
	for(int i=0;i<50;i++){
		stu[i].grade=i+1;
	}
	printf("姓名\t\t計概成績\t微積分成績\t平均\t排名\n-----------------------------------------------------------\n");
	for(int i=0;i<50;i++){
		printf("%11s\t\t%d\t\t%d\t%d\t%d\n",stu[i].name,stu[i].s1,stu[i].s2,stu[i].avg,stu[i].grade);
	}
	
	return 0;
}
