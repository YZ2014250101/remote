#include<stdio.h>
int main(){
	int i = 0;
	int arr[10] = {0};
	for(i = 0;i < 10;i++){
		scanf("%d",&arr[i]);
	}
	int hi = 0;
	int n = 0;
	scanf("%d",&hi);
	for(i = 0;i < 10;i++){
		if(hi+30 >= arr[i]){
			n++;
		}
	}
	printf("%d",n);
} 
