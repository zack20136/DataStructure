#include<stdio.h>
#include<stdlib.h>

int main(){
	int n=0;
	printf("´X¶¤¡G");
	scanf("%d",&n);
	int s[n],d[n],x[n],y[n];
	for(int i=0;i<n;i++){
		printf("S¡BD¡G");
		scanf("%d%d",&s[i],&d[i]);
	}
	
	for(int i=0;i<n;i++){
		if(d[i]>s[i]){
			x[i]=-1;
			y[i]=-1;
			continue;
		}
		int j;
		for(j=0;j<=s[i];j++){
			x[i]=j;
			y[i]=s[i]-x[i];
			if(x[i]-y[i]==d[i]){
				break;
			}
		}
		if(j>s[i]){
			x[i]=-1;
			y[i]=-1;
		}
	}
	
	for(int i=0;i<n;i++){
		if((x[i]==-1)&&(y[i]==-1)){
			printf("impossible\n");
		}
		else{
			printf("X:%d\tY:%d\n",x[i],y[i]);
		}
	}
	
	return 0;
} 
