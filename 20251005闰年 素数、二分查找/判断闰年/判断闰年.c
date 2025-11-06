#include<stdio.h>
int leapyear(year){
	if(year%4==0){
		if(year%100==0){
			if(year%400==0){
				return 1;
			}else{
				return 0;
			}
		}else{
			return 1;
		}
	}else{
		return 0;
	}
} 
int main(){
	int a=0;
	scanf("%d",&a);
	if(leapyear(a)==1){
		printf("%s","是闰年"); 
	} else{
		printf("%s","不是闰年"); 
	}
	return 0;
}
