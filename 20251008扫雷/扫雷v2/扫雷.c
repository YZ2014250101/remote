#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define const 10
void MarkMine(char show[ROWS][COLS], int row, int col){
	int x = 0;
	int y = 0;
	while (1){
		printf("请输入你想要标记位置的坐标->");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= ROW && y >= 1 && y <= COL){
			if (show[x][y] == '*')   {
				show[x][y] = '?';
				break;
			}else if(show[x][y] == '?'){
				show[x][y] ='*';
				break;
				
			}else{
				printf("该位置不能被标记，请重新输入!\n");
			}
		}
		else{
			printf("输入错误，请重新输入!\n");
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////
int num(char show[ROWS][COLS],int rows,int cols){
	int k=0,i=0,j=0;
	for(i=1;i<rows-1;i++){
		for(j=1;j<cols-1;j++){
       		if(show[i][j]=='*'){
       			k++;
			   }	
		}
	}
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////
void nonemine(char show[ROWS][COLS],char cons[ROWS][COLS],int x,int y){
	int i=0,j=0,k=0;
	show[x][y]=' ';
	for(i=x-1;i<=x+1;i++){
		for(j=y-1;j<=y+1;j++){
			if(show[i][j]=='*'){
				nonemine(show,cons,i,j);
			}
		}
	}

}
/////////////////////////////////////////////////////////////////////////////////////////////
void printshow(char show[ROWS][COLS],int rows,int cols){
	int i=0,j=0;
	printf("若要一直排雷，请在每次输入排雷坐标后\n按一次任意键+回车\n");
	printf("    1 2 3 4 5 6 7 8 9\n"); 
	printf("    -----------------\n");
	for(i=1;i<rows-1;i++){
	    printf("%-2d %c",i,'|');
		for(j=1;j<cols-1;j++){
       		printf("%c ",show[i][j]);	
		}
		printf("\n");
	}
	printf("    -----------------\n");
}
/////////////////////////////////////////////////////////////////////////////////////////////
void findmine(char show[ROWS][COLS],char cons[ROWS][COLS],int x,int y){
	int i=0,j=0,n=0;
	if(cons[x][y]=='!'){
		
		for(i=1;i<ROWS-1;i++){
			for(j=1;j<COLS-1;j++){
	       		if(cons[i][j]=='!'){
	       			show[i][j]='!';
				}	
			}
		}
		show[x][y]='!';
		printf("你被炸死了，游戏结束！\n你被炸死了，游戏结束！\n你被炸死了，游戏结束！\n"); 
		
	}else if(cons[x][y]=='*'){
		for(i=x-1;i<=x+1;i++){
			for(j=y-1;j<=y+1;j++){
				if (cons[i][j]=='!'){
				n++;
				}
			}
		}

	
			if(n==0){
				int k=0;
				show[x][y]=' ';
				for(i=x-1;i<=x+1;i++){
					for(j=y-1;j<=y+1;j++){
						if(show[i][j]=='*'&&i>=1&&i<=ROW&&j>=1&&j<=COL){
							findmine(show,cons,i,j);
						}
					}
				}
			}else{
			show[x][y]=n+'0';
			}	
	}	
}
/////////////////////////////////////////////////////////////////////////////////////////////
void setmine(char cons[ROWS][COLS],int row,int col) {
	int con=const;
	int i=0,j=0;
	while(con){
		int x=rand()%row+1;
		int y=rand()%col+1;
		if(cons[x][y]=='*'){
			cons[x][y]='!';
			con--;
		}
	}
	
}
//////////////////////////////////////////////////////////////////////////////////////////////
void consgener(char cons[ROWS][COLS],int rows,int cols){int i=0,j=0;
	for(i=0;i<rows;i++){		
		for(j=0;j<cols;j++){
		   cons[i][j]='*';
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////
void showprint(char show[ROWS][COLS],int rows,int cols){
	int i=0,j=0;
	for(i=0;i<rows;i++){		
		for(j=0;j<cols;j++){
		   show[i][j]='*';
		}
	}
	printf("    1 2 3 4 5 6 7 8 9\n"); 
	printf("    -----------------\n");
	for(i=1;i<rows-1;i++){
	    printf("%-2d %c",i,'|');
		for(j=1;j<cols-1;j++){
       		printf("%c ",show[i][j]);	
		}
		printf("\n");
	}
	printf("请输入两个数字用空格隔开作为行、列坐标\n") ;
}
/////////////////////////////////////////////////////////////////////////////////////////
game(){
	    char ch;
		char show[ROWS][COLS]={0};
		char cons[ROWS][COLS]={0};
		showprint(show,ROWS,COLS);
		consgener(cons,ROWS,COLS);
		setmine(cons,ROW,COL);
		int x=0,y=0,k=0;
		while(1){
			printf("当前为排雷模式\n");
			printf("请输入你想排查的坐标->");
			scanf("%d %d",&x,&y);
			if(x>=1&&x<=ROW&&y>=1&&y<=COL) {
				system("cls");
				findmine(show,cons,x,y);
				printshow(show,ROWS,COLS);
				if(show[x][y]=='!'){
					printf("-----0、EXIT 1、START------\n");
					printf("请输入0或1选择是否游戏>");
					
					break;
				}else{
					num(show,ROWS,COLS);
					if(num==0){
						printf("恭喜你，你已经排空所有雷获得胜利！"); 
					}
				}
			}else{
				printf("非法输入，请重新输入\n"); 
			}
			
			
			printf("若需要标记雷的位置请输入y/Y后按下回车\n否则请按下一次任意键后按下回车以继续排查坐标->");
			while ((ch = getchar()) != '\n');
			scanf("%c", &ch);
			if (ch == 'Y' || ch == 'y'){
				while(1){
					MarkMine(show, ROW, COL); 
					system("cls");
					printshow(show,ROWS, COLS);
					printf("再次输入y/Y可切换排雷模式\n");
					while (getchar()!= '\n');
					if (getchar()== 'Y' || ch == 'y'){
						break;
					}
				} 
				
			}else{
				continue;
			}
			
	}
} 
/////////////////////////////////////////////////////////////////////////////////////////////
int main(){
	int i=0,j=0,n=0;
	int input = 0;
	srand((unsigned int)time(NULL));

	do{	printf("---------------------------\n");
		printf("----开始一个9*9的扫雷?-----\n");
		printf("---------------------------\n");
		printf("-----0、EXIT 1、START------\n");
		printf("---------------------------\n");
		printf("请输入0或1选择是否游戏>");
		while(1){
			int ret1 = scanf("%d", &input);
	        if(ret1 != 1){  
	        
		        printf("非法输入，请输入0或1！\n");
		        while(getchar() != '\n'); 
		        break;
	   		}else{
		   			if(input==0){
					printf("退出游戏");
					while (getchar() != '\n');
					return 0;
				}else if(input==1){
					while (getchar()!= '\n');
					system("cls");
					game() ;	
				}else{
					printf("非法输入，请输入0或1\n"); 
					while (getchar() != '\n');
				}
    		}	
		}
	}
			
	while(1);
    return 0;
}
