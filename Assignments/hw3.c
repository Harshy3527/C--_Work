#include <stdio.h>
void prog31() {
    int i, low, high;
    printf("Enter the lower limit and upper limit :-\n");
    scanf("%d %d", &low, &high);
    for (i = low; i <= high; i++)
        printf("%d\n", i);
}
void prog32() {
    int i, low, high;
    printf("Enter the lower limit and upper limit:- \n");
    scanf("%d %d", &low, &high);
    i = (low % 2 == 0) ? low : (low++);
    for (i = low; i <= high; i += 2) {
        if (i % 2 == 0)
            printf("%d\n", i);
    }
}
void prog33() {
    int i, high, low, sum = 0;
    printf("Enter the lower limit and upper limit:- \n");
    scanf("%d %d", &low, &high);
    for (i = low; i <= high; i++) {
        sum += i;
    }
    printf("Sum = %d", sum);
}
void prog34() {
    int i, high, low, sumSq = 0;
    printf("Enter the lower limit and upper limit :- \n");
    scanf("%d %d", &low, &high);
    i = (low % 2 == 0) ? i : (i++);
    for (i = low; i <= high; i += 2) {
        sumSq += i * i;
    }
    printf("Sum of squares of even numbers from %d to %d = %d", low, high, sumSq);
}
void prog35() {
    int i, num, fact = 1;
    printf("Enter a number : ");
    scanf("%d", &num);
    for (i = 1; i <= num; i++) {
        fact *= i;
    }
    printf("%d! = %d", num, fact);
}
void prog36() {
    int digits, count = 0, num;
    printf("Enter a number : ");
    scanf("%d", &num);
    while (num > 0) {
        num /= 10;
        count++;
    }
    printf("The number of digits in %d = %d", num, count);
}
void prog37() {
    int digits, num, copy, revNum = 0;
    printf("Enter a number : ");
    scanf("%d", &num);
    copy = num;
    while (num > 0) {
        digits = num % 10;
        num /= 10;
        revNum = revNum * 10 + digits;
    }
    printf("Reverse of %d = %d", copy, revNum);
}
void prog38() {
    int digits, num, copy, revNum = 0;
    printf("Enter a number : ");
    scanf("%d", &num);
    copy = num;
    while (num > 0) {
        digits = num % 10;
        num /= 10;
        revNum = revNum * 10 + digits;
    }
    if (revNum == copy)
        printf("Yes, it is a palindrome");
    else
        printf("Not a palindrome");
}
void prog39() {
    int i, num;
    printf("Enter a number : ");
    scanf("%d", &num);
    for (i = 1; i <= 20; i++) {
        printf("%d * %d = %d", num, i, (num * i));
    }
}
void prog310() {
    int digits, num, copy, sumSq = 0;
    printf("Enter a number : ");
    scanf("%d", &num);
    copy = num;
    while (num > 0) {
        digits = num % 10;
        num /= 10;
        sumSq = sumSq + digits * digits;
    }
    printf((sumSq == copy) ? "Armstrong Number" : "Not an Armstrong Number");
}
void prog311() {
    int i, num, count = 0;
    printf("Enter a number : ");
    scanf("%d", &num);
    for (i = 2; i * i <= num; i++) {
        if (num % i == 0)
            count++;
    }
    if (count > 0)
        printf("It is a prime number.");
    else
        printf("Not a prime number");
}
void prog312() { //fibonacci series v1.0
    int i, n, j, s = 0;
    printf("Enter the number of terms : ");
    scanf("%d", &n);
    int f = 0, l = 1;
    printf("0 ");
    for (i = 0; i <= n; i++) {
        s = f + l;
        printf(" %d ", s);
        f =l; l = s;
    }
}
void prog313() {
    printf("Enter a Decimal Number : ");
    int decNum;
    scanf("%d", &decNum);
    if (decNum == 0) {
        printf("0 in binary = 0\n");
    }
    int binArr[32]; // Enough for 32-bit int
    int i = 0, copy = decNum;
    while (copy > 0) {
        binArr[i++] = copy % 2;
        copy /= 2;
    }
    printf("%d in binary = ", decNum);
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binArr[j]);
    }
    printf("\n");
}
void prog314() {
    printf("Enter a Decimal Number : ");
    int decNum;
    scanf("%d", &decNum);
    if (decNum == 0) {
        printf("0 in hexadecimal = 0\n");
    }
    int hexArr[32];// Enough for 32-bit int
    int i = 0,j=0, copy = decNum;
    while (copy > 0) {
        hexArr[i] = copy % 16;
        copy /= 16;
        i++;
    }
    printf("%d in  Hexadecimal = 0x", decNum);
    int k =0; char letter;; 
    for (int j = i - 1; j >= 0; j--) {      
        if (hexArr[j]>=10) {
            letter =(char) ((hexArr[j]-10)+65);
            printf("%c", letter); 
        }
        else
            printf("%d", hexArr[j]);
    }
    printf("\n");
}

void prog315() {
    int i, j, low, high, sum = 0;
    printf("Enter the lower limit and upper limit :- \n");
    scanf("%d %d", &low, &high);
    for (i = low; i <= high; i++) {
        if (i % 17 != 0)
            sum += i;
    }
    printf("The sum = %d", sum);
}

int main() {
    // prog31();
    // prog32();
    // prog34();
    prog314();
    // prog312(); 
}