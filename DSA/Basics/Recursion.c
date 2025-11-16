#include <stdio.h>
// A recursive method is one that invokes itself
long factorial(int n);
int fibonacci(int index);

int main() {
    int n;
    printf("Enter a number : ");
    scanf("%d", &n);
    printf((n>0)?"positive": "negative");
    printf("%d! = %ld \n", n, factorial(n));
    for (int i = 0; i <= n; i++) 
        printf(" %d ", fibonacci(i));
    
    return 0;
}

int fibonacci(int index) {
    if(index<0)
        return -1; 
    else if (index == 0)
        return 0;
    else if (index == 1)
        return 1;
    else
        return fibonacci(index - 1) + fibonacci(index - 2);
}

/*
long factorial(int n) {
        return n * factorial(n - 1);
}
The method runs infinitely and causes a StackOverflowError */

long factorial(int n) {
    if (n<0)
        return -1;
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}


