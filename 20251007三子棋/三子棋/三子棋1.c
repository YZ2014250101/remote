#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define ROW 3
#define COL 3

//展示棋盘 
void DisplayBoard(char board[ROW][COL],int row,int col){
	int i=0;
	for(i=0;i<row;i++){
	
		int j=0;
		for(j=0;j<col;j++){
       		printf(" %c ",board[i][j]);
			if(j<col-1){
			
			printf("|");
		    }
		}
		
		printf("\n");
		
		if(i<row-1){
		
			int j=0;
			for(j=0;j<col;j++){
				printf("---");
				if(j<col-1)
				printf("|") ;
			}
			printf("\n");
		}	
	}
}


//初始化棋盘 
void initboard(char board[ROW][COL],int row,int col){
	int i=0,j=0;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
		   board[i][j]=' ';
		}
	}
	
}


//玩家回合 
void PlayerMove(char board[ROW][COL],int row,int col){
	int x=0,y=0;
	while(1){
		
		
		scanf("%d %d",&x,&y);
		if(board[x-1][y-1]!=' '&&x<=ROW&&x>=1&&y<=COL&&y>=1){
			printf("该位置已有棋子，请另选坐标\n"); 
		}else if(board[x-1][y-1]==' '&&x<=ROW&&x>=1&&y<=COL&&y>=1){
			board[x-1][y-1]='*';
			DisplayBoard(board,row,col);
		    printf("电脑回合······\n");
			break;
	    }else{
	    	printf("输入非法，请重新输入>"); 
		}
		
	}
	
}


//电脑回合随机下子 
void ComputerMove(char board[ROW][COL],int row,int col){
	int x=0,y=0;
	
	while(1){
		srand((unsigned)time(NULL));
		int ret1 = rand();
		int ret2 = rand();
		x=ret1%ROW;
		y=ret2%COL;
	
		if(board[x][y]==' '&&x+1<=ROW&&x+1>=1&&y+1<=COL&&y+1>=1){
			board[x][y]='#';
			DisplayBoard(board,row,col);
			printf("电脑输入完毕\n现在为你的回合，请输入坐标>");
			break;
	    }
	}
}


//行判断 
int RowJudge(char board[ROW][COL],int row,int col){
	int i=0,j=1;
	for(j=COL%2;j<COL-COL%2;j++){
		for(i=0;i<COL;i++){
			
			
				if(board[i][j]=='*'&&board[i][j]==board[i][j+1]&&board[i][j]==board[i][j-1]
					){
					return 1;
				goto here;
				}else if(board[i][j]=='#'&&board[i][j]==board[i][j+1]&&board[i][j]==board[i][j-1]
					){
					return -1;
					goto here;
		         }  
			
		}
	}
	here:;
}	


//列判断	
int ColJudge(char board[ROW][COL],int row,int col){
	int i=1,j=0;
	for(i=ROW%2;i<ROW-ROW%2;i++){
		for(j=0;j<COL;j++){
			
			
				if(board[i][j]=='*'&&board[i][j]==board[i+1][j]&&board[i][j]==board[i-1][j]
					){
					return 1;
					goto here;
				}else if(board[i][j]=='#'&&board[i][j]==board[i+1][j]&&board[i][j]==board[i-1][j]
					){
					return -1;
					goto here;
				}
			
		}
	}
	here:;
}	


//斜对角判断 
	
int DiaJudge(char board[ROW][COL],int row,int col){
	int i=1,j=1;
	
			if(j<ROW-ROW%2&&j>=ROW%2&&j<COL-COL%2&&j>=COL%2){
			
				if(board[i][j]=='*'&&(board[i][j]==board[i+1][j+1]&&board[i][j]==board[i-1][j-1]
					||board[i][j]==board[i-1][j+1]&&board[i][j]==board[i+1][j-1])){
					return 1;
					goto here;
				}else if(board[i][j]=='#'&&(board[i][j]==board[i+1][j-1]&&board[i][j]==board[i-1][j+1]
					||board[i][j]==board[i-1][j-1]&&board[i][j]==board[i-1][j-1])){
					return -1;
					goto here;
				} 
	   	    }
	
	here:;
}	
	
	
//判断棋盘是否已满	
int FullJudge(char board[ROW][COL],int row,int col)	{
	int i=0,j=0,s=0;
	for(i=0;i<ROW;i++){
		for(j=0;j<COL;j++){
			if(board[i][j]==' '){
				s++;
				
				
			}
		}
	}
	return s;
}
	
	
//游戏 
void game(){
	char board[ROW][COL]={0};
	initboard(board,ROW,COL);
	DisplayBoard(board,ROW,COL);
	printf("请输入两个数字用空格隔开作为坐标>");
	while(1){
	
		PlayerMove(board,ROW,COL);
		if(ColJudge(board,ROW,COL)==1||RowJudge(board,ROW,COL)==1||DiaJudge(board,ROW,COL)==1){
			printf("恭喜你，你赢了\n要再来一局吗?\n");
			break; 
		}else if(FullJudge(board,ROW,COL)==0){
			printf("棋盘已满，此局为平局\n要再来一把吗?\n"); 
			break;
		}
		ComputerMove(board,ROW,COL);
		if(ColJudge(board,ROW,COL)==-1||RowJudge(board,ROW,COL)==-1||DiaJudge(board,ROW,COL)==-1){
			printf("很遗憾，你输了\n不甘心就再来一把吧！\n"); 
			break; 
		}else if(FullJudge(board,ROW,COL)==0){
			printf("棋盘已满，此局为平局\n要再来一把吗?\n"); 
			break;
		}
		
    }
    int i=0,j=0;
	printf("\n");

}



int main(){
	int i=0,j=0,n=0,k=0;
	int input = 0;

	do{	printf("**********************\n");
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

