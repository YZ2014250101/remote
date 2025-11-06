#include<stdio.h>
int gcd(int a, int b) {
    // 处理负数
    a = a < 0 ? -a : a;
    b = b < 0 ? -b : b;
    // 欧几里得算法核心逻辑
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a; // 当b=0时，a即为最大公约数
}
int lcm(int c, int d){

    return c*d/gcd(c,d);
}
int main(){
    int a=0,b=0,c=0,d=0;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    printf("最大公约数是%d\n最小公倍数是%d",gcd(a, b),lcm(c, d));
}
