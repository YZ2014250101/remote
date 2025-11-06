#include<stdio.h>
int main () {
	int k = 0;
	scanf("%d",&k);
	double s = 0;
	int n = 1;
	while (1) {
		s = s + (double)1/n;
		
		if(s > k){
			break;
		}
		n++;	
	}
	printf("%d",n);
	return 0;
}
