#include <limits.h>
int reverse(int x) {
    long rev = 0;   
    while (x != 0) {
        int pop = x % 10;
        x /= 10;
        rev = rev * 10 + pop;//每循环一次位数+1 
        if (rev > INT_MAX || rev < INT_MIN) {
            return 0;
        }
    }   
    return (int)rev;
}

