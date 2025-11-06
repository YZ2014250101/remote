#include<stdio.h>
#include<math.h>
int primePLUSprime(int i,int m,int n){
	int j = 2;
	int k = 0,count = 0; 
	for (j = 2; j <= i/2; j++) {
        if(prime(j)==1&&prime(i-j)==1){
        	k++;//统计式子个数 
		}
    }
    for (j = 2; j <= i/2; j++) {
        if(prime(j)==1&&prime(i-j)==1){
        	m=j;
        	n=i-j;
        	count++;
        	if(count==k){
        		printf("%d = %d + %d",i,m,n);
			}else{
				printf("%d = %d + %d\n",i,m,n);
			}
		}
    }
	
}

int prime(int i) {
	int j = 3;
    // 素数定义：大于1的自然数，除了1和自身外没有其他因数
    if (i <= 1) {
        return 0; // 1和小于1的数不是素数
    }
    if (i == 2) {
        return 1; // 2是最小的素数（唯一的偶数素数）
    }
    if (i % 2 == 0) {
        return 0; // 偶数（除2外）一定不是素数
    }
    // 只需检查到根号i即可，因为若i有因数大于根号i，
    // 则必有一个对应的因数小于根号i
    for (j = 3; j * j <= i; j += 2) {
        if (i % j == 0) {
            return 0; // 存在其他因数，不是素数
        }
    }
    return 1; // 没有找到其他因数，是素数
}
int main(){
	int m=0,n=0;
	printf("请输入6-200之间的一个偶数: \n");
	int a=0;
	scanf("%d",&a);
	while(a< 6 || a > 200 ||a % 2 != 0){
		while(getchar()!='\n');
		scanf("%d",&a);
	}
	primePLUSprime(a,m,n);
	
} 
