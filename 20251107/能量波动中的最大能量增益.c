#include<stdio.h>
int main(){
    int energy[1000]={0};
    int i = 0;
    int j = 0;

    int n = 0;
    scanf("%d",&n);
    for(i = 0 ;i<n;i++){
    	scanf("%d",&energy[i]);
	}
   
    
    int tmp = 0 ;

    for (i = 0;i<n;i++){
         for (j = i+1;j<n;j++){
            if(energy[j]-energy[i]>tmp){
                tmp = energy[j]-energy[i];
            }
        }
    }

    if(tmp!=energy[0]){
        printf("%d",tmp);
    }else if(tmp==energy[0])
    printf("0");
    return 0;
}
//在一个科幻基地中，有一台能量采集装置，它会记录每天的能量强度。
//能量强度随时间变化，由一个数组 energy 表示，其中第 i 个元素 energy[i] 表示第 i 天的能量值，数组的长度为 n 。
//
//你只能选择某一天启动装置（采集起点），并在之后某一天关闭装置（采集终点）。
//装置能收集的能量增益等于关闭时的能量值减去启动时的能量值。
//
//请你计算，装置在最佳启动和关闭时刻下，能够获得的 ?最大能量增益?。
//如果能量值一直下降或不变，返回 0。
