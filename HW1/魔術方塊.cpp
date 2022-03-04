#include<stdio.h>
#include<stdlib.h>
int flag=1;//計算是否撞到有數值格子的變數 
int generate(int square[],int size,int count,int max){//往左下 
	if(max<=2){//跳出遞迴的條件 
		return square[count]=size*size+1;
	}
	count=count-size-1;//往左上移動一格 
	if(count<0){//當左上沒有格子時，跳回最下面那行 
		count=count+size*size;
	}
	if(flag==size){//當撞到有數值的格子時，往下移動一格 
		flag=0;
		count=count+size*2+1;
	}
	else if((count+1)%size==0){//當向上跳行時，往下移動一格 
		count=count+size;
	}
	if(count>size*size){//當右下格子時，跳到最上面那行 
		count=count-size*size;
	}
	flag++;
	return square[count]=generate(square,size,count,max-1)-1;
}
int main(){
	int size=0;
	printf("Enter the size of the square:");
	scanf("%d",&size);
	if((size<1)||(size%2==0)){//除錯 
		printf("Error");
		exit(1);
	}
	int square[size*size]={0};
	int count=(size-1)/2;//設定起始位子 
	int max=size*size+1;//數值最大值 
	
	square[count]=generate(square,size,count,max)-1;//呼叫函數 
	
	for(int i=0;i<size*size;i++){//印出 
		printf("%3d ",square[i]);	
		if((i+1)%size==0){
			printf("\n");
		}
	} 
	return 0;
}
