#include<stdio.h>
#include <string.h>
long long memo[1000]; 
void init_memo() {
    memset(memo, -1, sizeof(memo));
    memo[1] = 0;
int energy(int n){
    int j=0;
    if (n == 1) {
        return 0;
    }
    if (n <=1000 && memo[n] != -1) {
        return memo[n];
        }
    
        if(n%2==0){
            energy(n/2);
            j=energy(n/2)+1;
        }else if(n%2==1&&n!=1){
           
            
            energy(n*3+1);
            j=energy(n*3+1)+1;
        }
        if (n <= 1000) {
        memo[n] = j;
        }
        
        return j;

    
}
int main(){
    int n=0;
    init_memo();
    scanf("%d",&n);
    printf("%d",energy(n));
}
