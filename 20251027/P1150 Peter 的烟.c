#include<stdio.h>
int num(int n, int k){
	if(n>=k)
	return num(n/k+n%k,k)+n/k;
	return 0;
	
}
int main(){
	int i = 0,j = 0;
	int n = 0,k = 0;
	scanf("%d %d",&n,&k);
	
	printf("%d",num(n,k)+n);
    return 0;
} 
