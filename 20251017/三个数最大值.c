#include<stdio.h>

int main(){
	int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    a=a>b?a:b;
    b=b>c?b:c;
    a=a>b?a:b;
    
    printf("%d",a);
    return 0;
} 
