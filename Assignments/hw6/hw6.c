#include <stdio.h>

void q514() {
    char s[100];
    int i = 0;
    printf("Enter string: ");
    getchar();
    gets(s);
    while (s[i] != '\0') i++;
    printf("Length = %d\n", i);
}

void q515() {
    char a[100], b[100];
    int i = 0, j = 0;
    printf("Enter first string: ");
    getchar();
    gets(a);
    printf("Enter second string: ");
    gets(b);
    while (a[i] != '\0') i++;
    while (b[j] != '\0') a[i++] = b[j++];
    a[i] = '\0';
    printf("Concatenated string = %s\n", a);
}

void q516() {
    char s[100];
    int i = 0, j, t;
    printf("Enter string: ");
    getchar();
    gets(s);
    while (s[i] != '\0') i++;
    j = i - 1;
    for (i = 0; i < j; i++, j--) {
        t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
    printf("Reversed = %s\n", s);
}

int factorial(int n) {
    int f = 1;
    for (int i = 1; i <= n; i++) f *= i;
    return f;
}

int is_prime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}

int is_palindrome(int n) {
    int rev = 0, copy = n;
    while (copy) {
        rev = rev * 10 + copy % 10;
        copy /= 10;
    }
    return rev == n;
}

void q61() {
    int choice, n;
    printf("1. Factorial\n2. Prime\n3. Palindrome\n");
    scanf("%d", &choice);
    printf("Enter number: ");
    scanf("%d", &n);
    switch (choice) {
        case 1: printf("Factorial = %d\n", factorial(n)); break;
        case 2: printf(is_prime(n) ? "Prime\n" : "Not prime\n"); break;
        case 3: printf(is_palindrome(n) ? "Palindrome\n" : "Not palindrome\n"); break;
        default: printf("Invalid choice\n");
    }
}

int array_max(int a[], int n) {
    int m = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > m) m = a[i];
    return m;
}

int array_min(int a[], int n) {
    int m = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] < m) m = a[i];
    return m;
}

void q62() {
    int n, a[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("Max = %d\nMin = %d\n", array_max(a, n), array_min(a, n));
}

int is_symmetric(int a[][10], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] != a[j][i]) return 0;
    return 1;
}

void q63() {
    int n, a[10][10];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    printf(is_symmetric(a, n) ? "Symmetric\n" : "Not symmetric\n");
}

int my_strlen(char s[]) {
    int i = 0;
    while (s[i]) i++;
    return i;
}

int my_strcmp(char a[], char b[]) {
    int i = 0;
    while (a[i] && b[i] && a[i] == b[i]) i++;
    return a[i] - b[i];
}

void my_strcpy(char d[], char s[]) {
    int i = 0;
    while ((d[i] = s[i]) != '\0') i++;
}

void my_strrev(char s[]) {
    int i = 0, j = my_strlen(s) - 1, t;
    while (i < j) {
        t = s[i]; s[i] = s[j]; s[j] = t;
        i++; j--;
    }
}

void my_strcat(char a[], char b[]) {
    int i = my_strlen(a), j = 0;
    while ((a[i++] = b[j++]) != '\0');
}

void q64() {
    char s1[100], s2[100], copy[100];
    getchar();
    printf("Enter first string: ");
    gets(s1);
    printf("Enter second string: ");
    gets(s2);
    printf("Length = %d\n", my_strlen(s1));
    printf("Compare = %d\n", my_strcmp(s1, s2));
    my_strcpy(copy, s1);
    printf("Copy = %s\n", copy);
    my_strrev(s1);
    printf("Reverse = %s\n", s1);
    my_strcat(copy, s2);
    printf("Concatenated = %s\n", copy);
}

int fact_rec(int n) {
    if (n == 0) return 1;
    return n * fact_rec(n - 1);
}

int fib_rec(int n) {
    if (n <= 1) return n;
    return fib_rec(n - 1) + fib_rec(n - 2);
}

int sum_digits(int n) {
    if (n == 0) return 0;
    return (n % 10) + sum_digits(n / 10);
}

int nCr_rec(int n, int r) {
    if (r == 0 || r == n) return 1;
    return nCr_rec(n - 1, r - 1) + nCr_rec(n - 1, r);
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void str_concat(char *a, char *b) {
    while (*a) a++;
    while ((*a++ = *b++));
}

int str_compare(char *a, char *b) {
    while (*a && *b && *a == *b) a++, b++;
    return *a - *b;
}

void str_reverse(char *s) {
    char *e = s, t;
    while (*e) e++;
    e--;
    while (s < e) {
        t = *s; *s = *e; *e = t;
        s++; e--;
    }
}

int max_matrix(int *a[], int r, int c) {
    int max = a[0][0];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (a[i][j] > max) max = a[i][j];
    return max;
}

int min_matrix(int *a[], int r, int c) {
    int min = a[0][0];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (a[i][j] < min) min = a[i][j];
    return min;
}

void multiply(int *A[], int *B[], int *C[], int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < c1; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

int main() {
    int choice;
    printf("\n=== MENU ===\n");
    printf("1: 5.14\n2: 5.15\n3: 5.16\n4: 6.1\n5: 6.2\n6: 6.3\n7: 6.4\n8: 6.5\n9: 6.6\n10: 6.7\n11: 6.8\n12: 6.9\n13: 6.10\n14: 6.11\n15: 6.12\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1: q514(); break;
        case 2: q515(); break;
        case 3: q516(); break;
        case 4: q61(); break;
        case 5: q62(); break;
        case 6: q63(); break;
        case 7: q64(); break;
        case 8: printf("%d\n", fact_rec(5)); break;
        case 9: printf("%d\n", fib_rec(10)); break;
        case 10: printf("%d\n", sum_digits(12345)); break;
        case 11: printf("%d\n", nCr_rec(5,2)); break;
        case 12: { int a=5,b=10; swap(&a,&b); printf("%d %d\n",a,b);} break;
        case 13: printf("Pointer string functions tested separately.\n"); break;
        case 14: printf("Matrix max/min tested separately.\n"); break;
        case 15: printf("Matrix multiplication tested separately.\n"); break;
        default: printf("Invalid choice\n");
    }
    return 0;
}
