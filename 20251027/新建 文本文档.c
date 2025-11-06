#include<stdio.h>
int num(int n, int k){
	if(n>=k)
	return num(n/k+n%k,k)+n/k;
	return 0;
	
}
int main(){
	int i = 10000;
	int K = 0;
	scanf ("%d",&K);
	for(i = 10000;i <=30000;i++ ){
		if(sub(i)/K==0){
			printf("%d",)
		}
	}
	
} 
