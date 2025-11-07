#include<stdio.h>
#include<stdlib.h>
int main(){
    int n = 0;
    int* arr=(int*)malloc(n*sizeof(int));
    scanf("%d",&n);
    int i = 0 ;
    int tmp = 0;
    int b= 0;
    int a = 0,k = -1, m = 0;
    while(scanf("%d",&arr[i++])==1);
    while(1){
        b = a;
        for(i = 0 ; i +1<n;i++){
            
            if(arr[i]>arr[i+1]){
                
                tmp = arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=tmp;
                a++;
                m++;
            }
        }
        k++;
        if(b==a)break;
    }
    
    printf("%d %d %d\n",a,k,m);
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
