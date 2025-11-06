#include<stdio.h>
int main()
{
    int a= 0;
    scanf("%d",&a);
    if(a>=0&&a<=100){
        if(a>=90)printf("A");
        if(a<90&&a>=80)printf("B");
        if(a<80&&a>=70)printf("C");
        if(a<70&&a>=60)printf("D");
        if(a<60)printf("E");
        
    }
}
