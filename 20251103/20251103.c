#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void find(char** arr,long long trs,int* x,int* y,int m){	
	while(trs%2==0){
			x++;
			trs/=2;
	}
	while(trs%3==0){
		y++;
		trs/=3;
	}
	arr[*x][*y]='X';
	
}
int main()
{
    long long trs, x = 0, y = 0, m;
    int i = 0,j = 0;
    scanf("%d",&m);
    char symbol = 'O';
    char **arr = (char**)malloc(m * sizeof(char*)); 
	for (i = 0; i < m; i++) {
	    arr[i] = (char*)malloc(m * sizeof(char));   
	}
    if(arr!=NULL){
    	for (i = 0; i < m; i++) {
		    for (j = 0; j < m; j++) {
		        arr[i][j] = symbol;
		    }
		}
	} 
	find(arr,trs,&x,&y,m);
	while(1){
		x=0;
		y=0;
		scanf("%lld",&trs);
		if(trs==-1)break;
		find(arr,trs,&x,&y,m);
		
	}
	
	for(i=0;i<m;i++){
		for(j=0;j<m;j++){
			printf("%c",arr[i][j]);
		}
	}
	

    return 0;
}
