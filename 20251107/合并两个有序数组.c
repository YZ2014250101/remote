#include<stdio.h>
#include<stdlib.h>
int cmpfunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main(){
    int m = 0,n = 0;
    scanf("%d %d",&m,&n);
    int* nums1=(int *)malloc((m+n)*sizeof(int));
    int* nums2=(int *)malloc(n*sizeof(int));
    int i = 0;


    for(i = 0 ;i < m;i++){
        scanf("%d",&nums1[i]);
    }
    for(i = 0 ;i < n;i++){
        scanf("%d",&nums2[i]);
    }

    for(i = m;i < m + n;i++){
        nums1[i]=nums2[i-m];
    }

    qsort(nums1, m+n, sizeof(int), cmpfunc);

    for(i = 0;i < m + n;i++){
        printf("%d ",nums1[i]);
    }

    free(nums1);
    free(nums2);
}
