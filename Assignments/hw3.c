#include <stdio.h>
#include <math.h>

// 3.1
void prog31() {
    int low, high;
    printf("Enter the lower and upper limits: ");
    scanf("%d %d", &low, &high);
    for (int i = low; i <= high; i++)
        printf("%d ", i);
    printf("\n");
}

// 3.2
void prog32() {
    int low, high;
    printf("Enter the lower and upper limits: ");
    scanf("%d %d", &low, &high);
    low = (low % 2 != 0)? low+1: low;
    for (int i = low; i <= high; i += 2)
        printf("%d ", i);
    printf("\n");
}

// 3.3
void prog33() {
    int low, high, sum = 0;
    printf("Enter the lower and upper limits: ");
    scanf("%d %d", &low, &high);
    for (int i = low; i <= high; i++)
        sum += i;
    printf("Sum = %d\n", sum);
}

// 3.4
void prog34() {
    int low, high;
    printf("Enter the lower and upper limits: ");
    scanf("%d %d", &low, &high);
    if (low % 2 != 0) low++;
    printf("Even number squares:\n");
    for (int i = low; i <= high; i += 2)
        printf("%d^2 = %d\n", i, i * i);
}

// 3.5
void prog35() {
    int num, fact = 1;
    printf("Enter a number: ");
    scanf("%d", &num);
    for (int i = 1; i <= num; i++)
        fact *= i;
    printf("%d! = %d\n", num, fact);
}

// 3.6
void prog36() {
    int num, count = 0, copy;
    printf("Enter a number: ");
    scanf("%d", &num);
    copy = num;
    if (num == 0) count = 1;
    while (num != 0) {
        num /= 10;
        count++;
    }
    printf("Number of digits in %d = %d\n", copy, log10(abs(copy))+1);
}

// 3.7
void prog37() {
    int num, copy, rev = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    copy = num;
    while (num>10) {
        rev = rev * 10 + (num % 10);
        num /= 10;
    }
    printf("Reverse of %d = %d\n", copy, rev);
}

// 3.8
void prog38() {
    int num, copy, rev = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    copy = num;
    while (num > 0) {
        rev = rev * 10 + (num % 10);
        num /= 10;
    }
    if (rev == copy)
        printf("%d is a Palindrome number.\n", copy);
    else
        printf("%d is not a Palindrome number.\n", copy);
}

// 3.9
void prog39() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    for (int i = 1; i <= 20; i++)
        printf("%d × %d = %d\n", num, i, num * i);
}

// 3.10
void prog310() {
    int num, copy, rem, sum = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    copy = num;
    while (num > 0) {
        rem = num % 10;
        sum += rem * rem * rem; // 3-digit Armstrong
        num /= 10;
    }
    if (sum == copy)
        printf("%d is an Armstrong number.\n", copy);
    else
        printf("%d is not an Armstrong number.\n", copy);
}

// 3.11
void prog311() {
    int num, i, isPrime = 1;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (num <= 1) isPrime = 0;
    for (i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            isPrime = 0;
            break;
        }
    }
    if (isPrime)
        printf("%d is a Prime number.\n", num);
    else
        printf("%d is not a Prime number.\n", num);
}

// 3.12
void prog312() {
    int n, a = 0, b = 1, next;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Fibonacci Series: %d %d ", a, b);
    for (int i = 3; i <= n; i++) {
        next = a + b;
        printf("%d ", next);
        a = b;
        b = next;
    }
    printf("\n");
}

// 3.13
void prog313() {
    int dec, bin[32], i = 0;
    printf("Enter a decimal number: ");
    scanf("%d", &dec);
    int copy = dec;
    if (dec == 0) {
        printf("0 in binary = 0\n");
        return;
    }
    while (copy > 0) {
        bin[i++] = copy % 2;
        copy /= 2;
    }
    printf("%d in binary = ", dec);
    for (int j = i - 1; j >= 0; j--)
        printf("%d", bin[j]);
    printf("\n");
}

// 3.14
void prog314() {
    int dec, hex[32], i = 0;
    printf("Enter a decimal number: ");
    scanf("%d", &dec);
    int copy = dec;
    if (dec == 0) {
        printf("0 in hexadecimal = 0\n");
        return;
    }
    while (copy > 0) {
        hex[i++] = copy % 16;
        copy /= 16;
    }
    printf("%d in hexadecimal = 0x", dec);
    for (int j = i - 1; j >= 0; j--) {
        if (hex[j] >= 10)
            printf("%c", 'A' + (hex[j] - 10));
        else
            printf("%d", hex[j]);
    }
    printf("\n");
}

// 3.15
void prog315() {
    int low, high, sum = 0;
    printf("Enter the lower and upper limits: ");
    scanf("%d %d", &low, &high);
    for (int i = low; i <= high; i++) {
        if (i % 17 != 0)
            sum += i;
    }
    printf("Sum of numbers not divisible by 17 between %d and %d = %d\n", low, high, sum);
}

int main() {
    int choice;
    do {
        printf("\n====== ASSIGNMENT – III MENU ======\n");
        printf("1.  Print all natural numbers upto a range\n");
        printf("2.  Print all even numbers upto a range\n");
        printf("3.  Calculate sum of all natural numbers upto a range\n");
        printf("4.  Print squares of even numbers upto a range\n");
        printf("5.  Find factorial of a number\n");
        printf("6.  Count digits of a number\n");
        printf("7.  Reverse a number\n");
        printf("8.  Check palindrome number\n");
        printf("9.  Print multiplication table upto 20\n");
        printf("10. Check Armstrong number\n");
        printf("11. Check Prime number\n");
        printf("12. Print Fibonacci series\n");
        printf("13. Convert decimal to binary\n");
        printf("14. Convert decimal to hexadecimal\n");
        printf("15. Sum of numbers not divisible by 17 between two integers\n");
        printf("0.  Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1: prog31(); break;
            case 2: prog32(); break;
            case 3: prog33(); break;
            case 4: prog34(); break;
            case 5: prog35(); break;
            case 6: prog36(); break;
            case 7: prog37(); break;
            case 8: prog38(); break;
            case 9: prog39(); break;
            case 10: prog310(); break;
            case 11: prog311(); break;
            case 12: prog312(); break;
            case 13: prog313(); break;
            case 14: prog314(); break;
            case 15: prog315(); break;
            case 0: printf("Exiting... Goodbye!\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 0);

    return 0;
}
