#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

bool isValid(char* s) {
    int len = strlen(s);
    int i = 0;
    char* stack = (char*)malloc(sizeof(char) * (len ));
    int top = -1; 
    
    for (i = 0; i < len; i++) {
        char c = s[i];
   
        if (c == '(') {
            stack[++top] = ')';
        } else if (c == '[') {
            stack[++top] = ']';
        } else if (c == '{') {
            stack[++top] = '}';
        } else {
      
            if (top == -1 || stack[top--] != c) {
                free(stack);
                return false;
            }
        }
    }
    
    free(stack);
  
    return top == -1;
}
int main(){
	char s[10000]={'0'};
	scanf("%s",s);
	if(isValid(s)){
		printf("true");
	}else{
		printf("false");
	}
	return 0;
	
}
