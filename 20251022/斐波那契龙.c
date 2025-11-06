#include<stdio.h>
#include <math.h>
int is_prime(int num) {
	int i = 5;
	if (num == 2 || num == 3) {
		return 1;
	}
	if (num % 6 != 1 && num % 6 != 5) {
		return 0;
	}
	for ( i = 5; i <= sqrt(num); i += 6) {
		if (num % i == 0 || num % (i + 2) == 0) {
			return 0;
		}
	}
	return 1;
}
long long dragon_power(int day) {
    if (day == 0 || day == 1) {
        return 1;
    }

    long long prev_sum = dragon_power(day - 1) + dragon_power(day - 2);
   
    if (is_prime(day) == 1) {
        return prev_sum + day;
    } else if (day > 2 && day % 2 == 0) {
        return prev_sum - 1;
    } else {
        
        return prev_sum;
    }
}


int main() {
    int day;
    scanf("%d", &day);
    long long result = dragon_power(day);
    printf("%lld\n", result);
    return 0;
}
