#include<stdio.h>
#include<stdlib.h>
#define max 50

int cal(char *input){//計算前置式 
	int num[max]={0};//用來暫存數字的陣列 
	int i;//用來存input長度的變數 
	for(i=0;input[i]!='\0';i++){//計算input長度，順便將值存入num裡 
		switch(input[i]){
			case '+': 
			case '-': 
        	case '*': 
			case '/': 
			case '%'://當遇到+ - * / %時，將-9999存入num裡 
				num[i]=-9999;
				break;//跳出 
        	default://其他，將input的值存入num裡 
				num[i]=input[i]-'0';
				break;//跳出 
		}
	}
	//當遇到連在一起的兩個數值時，用前一個運算子去計算
	//然後將計算出來的值存入這個計算子的位置，最後將陣列往前推直到覆蓋運算過的兩個數字 
	for(int j=0;j<i;j++){
		if((num[j]!=-9999)&&(num[j+1]!=-9999)){//當num[j]和num[j+1]都不等於-9999時，執行 
			switch(input[j-1]){
				case '+'://當遇到+時，將兩個數num[j] num[j+1]相加並存入num[j-1] 
					num[j-1]=num[j]+num[j+1];
					break;
				case '-'://當遇到-時，將兩個數num[j] num[j+1]相r減並存入num[j-1]
					num[j-1]=num[j]-num[j+1];
					break;
        		case '*'://當遇到*時，將兩個數num[j] num[j+1]相乘並存入num[j-1]
					num[j-1]=num[j]*num[j+1];
					break;
				case '/'://當遇到/時，將兩個數num[j] num[j+1]相除並存入num[j-1]
					num[j-1]=num[j]/num[j+1];
					break;
				case '%'://當遇到%時，將兩個數num[j] num[j+1]模數並存入num[j-1]
					num[j-1]=num[j]%num[j+1];
					break;
			}
			for(int k=j;k<i;k++){//將陣列num[j-1]以後的都往前推兩個 
				input[k]=input[k+2];
				input[k+1]=input[k+3];
				num[k]=num[k+2];
				num[k+1]=num[k+3];
			}
			i-=2;//利用i和j，去讓迴圈做到只剩下num[0]有數字為止 
			j=0;
		}
	}
	return num[0];//回傳數值 
}

int main(){
	while(1){
		char input[max]={'\0'};//用來存輸入的陣列 
		int ans;//用來存答案的變數 
		printf("輸入要計算的前置式（輸入0結束）：");
		scanf("%s",&input);//輸入 
		if(input[0]=='0')//當input[0]等於0時，執行 
			if(input[1]=='\0')//當input[1]等於'\0'時，執行 
				break;//跳出 
		ans=cal(input);//呼叫計算前置式的函式 
		printf("答案：%d\n",ans);//輸出 
	}
	return 0;
}
