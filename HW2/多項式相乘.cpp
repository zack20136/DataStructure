#include<stdio.h>
#include<stdlib.h>

struct Array{
	int num;
	int exp;
};

int add(Array *arr,int k,int n){//將次方項一樣的加起來 
	for(int i=k;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i].exp==arr[j].exp){//當次方相等，將兩項係數相加 
				arr[i].num+=arr[j].num;
				while(arr[j+1].num!=0){//用後一個數取代被相加的數的位置 
					arr[j]=arr[j+1];
					j++;
				}
				arr[j].num=0;//將多出來的位置歸零 
				arr[j].exp=0;
				n--;//將結尾位置向前移動1 
				i--;
			}
		}
	}
	return n;
}

void sort(Array *arr,int k,int n){//將次方項從大排到小
	for(int i=k;i<n;i++){ 
		for(int j=i+1;j<n;j++){
			if(arr[i].exp<arr[j].exp){//當前項次方小於後項時，將兩項交換位置 
				Array temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
}

int main(){
	Array arr[200]={0};
	int s1,s2,f1,f2;//存取多項式開頭和結尾的變數 
	int n=0;//運算子 
	
	//多項式1 
	s1=n;//設定多項式1開頭位置 
	while(1){
		int in1,in2;
		printf("多項式1（係數 次方）：");
		scanf("%d %d",&in1,&in2);
		if((in1==0)&&(in2==0))//當都是0時，跳出迴圈 
			break;
		if(in1==0)//當係數是0時，直接忽略此次動作 
			continue;
		arr[n].num=in1;
		arr[n].exp=in2;
		n++;
	}
	f1=n;//設定多項式1結尾位置
	n=add(arr,s1,f1);//把次方一樣的項相加 
	sort(arr,s1,f1);//從次方大排到小 
	f1=n;//設定多項式1結尾位置
	printf("多項式1：");//印出多項式1
	for(int i=s1;i<f1;i++){
		printf("%dx^%d ",arr[i].num,arr[i].exp);
		if(i==f1-1)
			break;
		printf(" + ");
	}
	printf("\n\n");
	
	n++;
	//多項式2
	s2=n;//設定多項式2開頭位置
	while(1){
		int in1,in2;
		printf("多項式2（係數 次方）：");
		scanf("%d %d",&in1,&in2);
		if((in1==0)&&(in2==0))//當都是0時，跳出迴圈 
			break;
		if(in1==0)//當係數是0時，直接忽略此次動作
			continue;
		arr[n].num=in1;
		arr[n].exp=in2;
		n++;
	}
	f2=n;//設定多項式2結尾位置
	n=add(arr,s2,f2);//把次方一樣的項相加 
	sort(arr,s2,f2);//從次方大排到小 
	f2=n;//設定多項式2結尾位置
	printf("多項式2：");//印出多項式2 
	for(int i=s2;i<f2;i++){
		printf("%dx^%d ",arr[i].num,arr[i].exp);
		if(i==f2-1)
			break;
		printf(" + ");
	}
	printf("\n\n");
	
	n++;
	int k=n;//相乘 
	for(int i=s1;i<f1;i++){
		for(int j=s2;j<f2;j++){
			arr[n].num=arr[i].num*arr[j].num;
			arr[n].exp=arr[i].exp*arr[j].exp;
			n++;
		}
	}
	
	n=add(arr,k,n);//把次方一樣的項相加 
	sort(arr,k,n);//從次方大排到小 
	while(1){//印出 
		printf("%dx^%d",arr[k].num,arr[k].exp);
		k++;
		if(arr[k].num==0)
			break;
		printf(" + ");
	}
	
	return 0;
}
