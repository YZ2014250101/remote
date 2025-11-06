#include<stdio.h>
int main(){
	int i = 0,j = 0;
	int l = 0;
	int m = 0;
	int u = 0,v = 0;
	int arr[10001] = {0};
	int n = 0;
	scanf("%d%d",&l,&m);
	for(i = 0;i <= l;i++){
		arr[i] = 1;
	}
	for(i = 0;i < m;i++){
		scanf("%d%d",&u,&v);
		for(j = u;j <= v;j++){
			arr[j] = 0;
		}
	}
	for(i = 0;i <= l;i++){
		if(arr[i] == 1)n++;
	}
	
	printf("%d",n);
} 
