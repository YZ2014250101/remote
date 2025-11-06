#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#define ROW 9+2
#define COL 9+2
#define ROWs 9+2
#define COLs 9+2

void judge(char board[ROW][COL],char board2[ROW][COL],int row,int col,int x,int y){
	int i=0,j=0,n=0;
	if(board2[x][y-1]!='!'&&board2[x-1][y]!='!'&&board2[x-1][y+1]!='!'&&board2[x][y-1]!='!'&&board2[x][y+1]!='!'&&board2[x+1][y-1]!='!'&&board2[x+1][y]!='!'&&board2[x+1][y+1]!='!'){
		board[x][y]=' ';
		board[x-1][y-1]=' ';
		board[x-1][y]=' ';
		board[x-1][y+1]=' ';
		board[x][y-1]=' ';
		board[x][y+1]=' ';
		board[x+1][y-1]=' ';
		board[x+1][y]=' ';
		board[x+1][y+1]=' ';	
			
		}
		
		
		
		
	else{
		
		for(i=-1;i<=1;i++){
			for(j=-1;j<=1;j++){
				if (board2[x+i][x+j]=='!'){
					n++;
				}
			}
		}
		printf("%d\n",n);
		board[x][y]=n+'0';
	
	}
	
}


void PlayerMove(char board[ROW][COL],char board2[ROW][COL],int row,int col){
	int x=0,y=0,i=0,j=0;
	while(1){
		
		
		scanf("%d %d",&x,&y);
		if(board2[x][y]=='!'&&x<=ROW&&x>=1&&y<=COL&&y>=1){
		    printf("你已被炸死！\n");
		 	break;
		}else if(board2[x][y]=='*'&&x<=ROW&&x>=1&&y<=COL&&y>=1){
	    	judge(board,board2,ROW,COL,x,y);
	    	for(i=-1;i<=1;i++){
				for(j=-1;j<=1;j++){
					judge(board,board2,ROW,COL,x+i,y+j);
				}
			DisplayBoard(board,ROW,COL);
			DisplayBoard(board2,ROW,COL);		
	}
	
}
}
}

void setmine(char board[ROW][COL],int row,int col){
	
	int x=0,y=0;
	int i=0,j=0;
	for(i=0;i<10;i++){
		srand((unsigned)time(NULL));
		int ret1=rand();
		int ret2=rand();
		x=ret1%(ROW-2)+1;
		y=ret2%(COL-2)+1;
		if (board[x][y]=='!'){
			i--;
		}	
	
		board[x][y]='!';
	}
}


void initboard(char board[ROW][COL],int row,int col){
	int i=0,j=0;
	
	for(i=0;i<row;i++){
		
		for(j=0;j<col;j++){
		   board[i][j]='*';
		}
	}
}


void DisplayBoard(char board[ROW][COL],int row,int col){
	int i=0;
	printf("    1 2 3 4 5 6 7 8 9\n"); 
	printf("    -----------------\n");
	for(i=1;i<row-1;i++){
	    printf("%-2d %c",i,'|');
		int j=1;
		for(j=1;j<col-1;j++){
       		printf("%c ",board[i][j]);
			
		}
	
		printf("\n");
}
		
}








game(){
	char board[ROW][COL]={0};
	char board2[ROW][COL]={0};
	initboard(board,ROW,COL);
	DisplayBoard(board,ROW,COL);
	printf("正在埋雷，请耐心等待···\n"); 
   
	initboard(board2,ROW,COL);
	setmine(board2,ROW,COL);
	DisplayBoard(board2,ROW,COL);
	printf("埋雷完毕，可开始游戏~\n请输入你想排雷位置坐标->");
	PlayerMove(board,board2,ROW,COL);
}






int main(){
	int i=0,j=0,n=0,k=0;
	int input = 0;

	do{	printf("**********************\n");
		printf("*开始一个9*9的扫雷吗?*\n");
		printf("**********************\n");
		printf("***0、退出  1、开始***\n");
		printf("**********************\n");
		printf("请输入0或1选择是否游戏>");
		scanf("%d",&input);
			if(input==0){
				printf("退出游戏");
				return 0;
			}else if(input==1){
				game() ;	
			} else{
				printf("非法输入，请重新输入\n"); 
			}
    }	
	while(1);
    return 0;
}


