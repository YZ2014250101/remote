#include<stdio.h>
#include<stdlib.h>
int main(){
    int n = 0,m = 0,k = 0;
    scanf("%d%d%d",&n,&m,&k);
    int* nums=(int*)malloc(n*sizeof(int));
    
    int tmp = 0;
    int i = 0,j = 0,p = 0;
    while(scanf("%d",&nums[i++])==1);
    
    for(i = 0 ;i<n;i+=m){
        if(n-i<m){
            m=n-i;
        }
        

        for(p = 0;p<k;p++){
            j = m-1;
            tmp = nums[i+j];
            for(j = m-1;j>0;j--){
                nums[i+j]=nums[i+j-1];
            }
            nums[i]=tmp;

        }
        
    }
    for(i = 0 ;i<n;i++){
        printf("%d ",nums[i]);
    }
    free(nums);
}
