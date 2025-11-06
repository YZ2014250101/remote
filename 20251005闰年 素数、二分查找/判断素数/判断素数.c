#include<stdio.h>
 int Prime(int num1){
    int i=0;
	for(i=2;i<num1;i++){
		if(num1 % i == 0){
			return 1;
		}
	}
 } 
 int main(){
 	int a=0;
 	scanf("%d",&a);
 	if(Prime(a)==1){
 		printf("%s","不是素数"); 
	 }else{
	 	printf("%s","是素数"); 
	 } 
	 return 0; 
 }
