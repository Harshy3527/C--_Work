#include <stdio.h>
int factorial(int n); 
int main(){
    int num; 
    printf("Enter a number : "); 
    scanf("%d", &num);
    printf("Factorial of %d = %d", num, factorial(num));  
}

int factorial(int n){
    if (n==1||n==0)
    {
        return 1;
    }
    else if(n<=0)
        return -1; 
    
    return n*factorial(n-1); 
}