#include<stdio.h>
float C(float F){
	return 5*(F-32)/9;
}

int main(){
	float F=0;
	scanf("%f",&F);
	printf("c=%.2f",C(F)); 
} 
