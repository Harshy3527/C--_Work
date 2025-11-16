#include <stdio.h>

int fact(int N) {
    int pr = 1;
    for (int i = 1; i <= N; i++)
        pr *= i;
    return pr; 
}

int isPrime(int N){
    for(int i =2; i*i<N; i++)
        if(N%i==0) return 0; 
    return 1; 
}

int isPalindrome(int N){
    int n = N, revNum =0; 
    while(n>0){
        int digit = n%10; 
        revNum= revNum*10+digit; 
        n/=10; 
    }
    if(revNum==N) return 1; 
    else return 0; 
}

int main() {
    int choice, N;
    printf("Enter 1 for Factorial, 2 for Prime Check, 3 for Palindrome Check : \n");
    scanf("%d", &choice);
    printf("Enter the number : ");
    scanf("%d", &N);
    switch(choice) {
    case 1:
        printf("Factorial of %d = %d", N, fact(N));
        break;
    case 2:
        printf(isPrime(N) ? "Prime Number" : "Composite Number");
        break;
    case 3:
        printf(isPalindrome(N) ? "Palindrome" : "Not Palindrome");
        break;
    default:
        printf("Invalid Input");
    }
    return 0; 
}