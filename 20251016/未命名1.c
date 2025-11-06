#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

// 爱心图案（6行高）
char heart[6][20] = {
    "   **   **  ",
    "  **** ****",
    " ***********",
    "  *********  ",
    "    ***** ",
    "      * "
};

// 控制台窗口宽度（可根据实际调整）
#define WIDTH 80
// 颜色列表（控制台支持的16种颜色）
int colors[] = {
    0x02,0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,
    0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F
};
int color_count = 14;

// 设置控制台文本颜色
void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

// 移动光标位置
void setCursorPosition(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// 隐藏光标
void hideCursor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(hConsole, &cursor_info);
}

int main() {
    int pos = WIDTH;  // 爱心初始位置（右侧外部）
    int color_idx;    // 当前颜色索引
    srand((unsigned int)time(NULL));
    hideCursor();     // 隐藏光标，避免闪烁
	int i = 0;
    while (1) {
        system("cls");  // 清屏
        color_idx = rand() % color_count;  // 随机选择颜色
        
        // 绘制爱心（6行）
        for (i  = 0; i < 6; i++) {
            setCursorPosition(pos, 5 + i);  // 固定在屏幕中间偏上位置
            setColor(colors[color_idx]);
            printf("%s", heart[i]);
        }
        
        setColor(0x07);  // 恢复默认颜色
        pos--;           // 向左移动
        
        // 当爱心完全移出左侧时，重新从右侧进入
        if (pos < -20) {
            pos = WIDTH;
        }
        
        Sleep(200);  // 控制滚动速度（值越小越快）
    }
    
    return 0;
}
