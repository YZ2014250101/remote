#include<stdio.h>
void swap(int* px,int* py){
	int tmp=*px;
	*px=*py;
	*py=tmp;
}

int sort(arr){
	int i = 0;
	int a = 0;
	for(i=0;i<65535;i++){
		if(arr[i+1]>arr[i]){
			swap(arr[i+1],arr[i]);
			
		}
	}
	return arr;
}


int main(){
	int arr[65535];
	scanf("%d",arr[65535]);
	printf("%d",sort(arr[65535]));
}
