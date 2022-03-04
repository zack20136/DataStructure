#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 50000//限制最多移動幾次 

int move(int *arr,int *p1,int *p2,int n,int m){
	int flag=0;//用來判斷此次移動是否成功的變數 
	int x=*p1,y=*p2;//用x,y暫時將p1,p2的值存起來 
	switch(rand()%8){//產生為0～7的亂數 
		case 0://向右走 
			y++;
			if(y>m){//當超出邊界，忽略此次行為 
				flag=1;
			}
			break;
		case 1://向右下走
			x++;
			y++;
			if((x>n)||(y>m)){//當超出邊界，忽略此次行為
				flag=1;
			}
			break;
		case 2://向下走 
			x++;
			if(x>n){//當超出邊界，忽略此次行為
				flag=1;
			}
			break;
		case 3://向左下走 
			x++;
			y--;
			if((x>n)||(y<1)){//當超出邊界，忽略此次行為
				flag=1;
			}
			break;
		case 4://向左走 
			y--;
			if(y<1){//當超出邊界，忽略此次行為
				flag=1;
			}
			break;
		case 5://向左上走 
			x--;
			y--;
			if((x<1)||(y<1)){//當超出邊界，忽略此次行為
				flag=1;
			}
			break;
		case 6://向上走 
			x--;
			if(x<1){//當超出邊界，忽略此次行為
				flag=1;
			}
			break;
		case 7://向右上走 
			x--;
			y++;
			if((x<1)||(y>m)){//當超出邊界，忽略此次行為
				flag=1;
			}
			break; 
	}
	if(flag==0){//當flag=0，讓count[x][y]加一，並且將x,y存回p1,p2，最後回傳0 
		arr[x*m-(m-y)-1]++;
		*p1=x;
		*p2=y;
		return 0;
	}
	else{//如果flag!=0，回傳1 
		return 1;
	}
}

int check(int *arr,int num){//檢查是否每個格子都走過一次了 
	for(int i=0;i<num;i++){
		if(arr[i]==0){//如果陣列裡有一個等於0的就跳出，回傳零 
			return 0;
		}
	}
	return 1;//當全部陣列都不是0，回傳0 
}

int main(){
	srand(time(NULL));
	int n=15,m=15;//大小 
	int p1=10,p2=10;//起始位置 
	printf("大小(n*m)：");
	scanf("%d%d",&n,&m);
	printf("起始位置(x,y)：");
	scanf("%d%d",&p1,&p2);
	int count[n][m];//計算哪格走過幾次的陣列 
	for(int i=0;i<n;i++){//將陣列初始化 
		for(int j=0;j<m;j++){
			count[i][j]=0;
		}
	}
	
	for(int i=0;i<MAX;i++){//在規定的次數以內，讓其移動 
		i-=move(*count,&p1,&p2,n,m);//呼叫函式 
		if(check(*count,n*m)==1){//當檢查過了，跳出迴圈 
			printf("當走第%d步時，每格都走過1次\n\n",i+1);
			break;
		}
	}
	
	int k=0;//排版 
	for(int i=0;i<n;i++){//印出哪格走到過幾次 
		for(int j=0;j<m;j++){
			printf("(%2d,%2d)：%5d次  ",i+1,j+1,count[i][j]);
			k++;//排版 
			if(k>2){//排版 
				printf("\n");
				k=0;
			}
		}
	}
	return 0;
}
