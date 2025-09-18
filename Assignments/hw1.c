#include <stdio.h>
#include <math.h>

// 1.1 Print name, date of birth, mobile number (using scanf)
void program1_1() {
    char name[50], dob[20], mobile[15];
    printf("Enter your name: ");
    scanf("%49s", name);
    printf("Enter your date of birth (DD/MM/YYYY): ");
    scanf("%19s", dob);
    printf("Enter your mobile number: ");
    scanf("%14s", mobile);
    printf("\n--- Your Details ---\n");
    printf("Name: %s\n", name);
    printf("Date of Birth: %s\n", dob);
    printf("Mobile: %s\n", mobile);
}

// 1.2 Print characters in reverse order
void program1_2() {
    char a, b, c;
    printf("Enter three characters: ");
    scanf(" %c %c %c", &a, &b, &c);
    printf("Reverse: %c%c%c\n", c, b, a);
}

// 1.3 Sum and product of two integers
void program1_3() {
    int x, y;
    printf("Enter two integers: ");
    scanf("%d %d", &x, &y);
    printf("Sum = %d\n", x + y);
    printf("Product = %d\n", x * y);
}

// 1.4 Perimeter & area of rectangle (user input)
void program1_4() {
    int h, w;
    printf("Enter height and width of rectangle: ");
    scanf("%d %d", &h, &w);
    printf("Perimeter = %d\n", 2 * (h + w));
    printf("Area = %d\n", h * w);
}

// 1.5 Perimeter & area of circle (user input)
void program1_5() {
    float r;
    printf("Enter radius: ");
    scanf("%f", &r);
    float pi = 3.14159;
    printf("Perimeter = %.2f\n", 2 * pi * r);
    printf("Area = %.2f\n", pi * r * r);
}

// 1.6 Display ASCII value of character
void program1_6() {
    char ch;
    printf("Enter a character: ");
    scanf(" %c", &ch);
    printf("ASCII value = %d\n", ch);
}

// 1.7 Convert capital letter to small letter
void program1_7() {
    char ch;
    printf("Enter a capital letter: ");
    scanf(" %c", &ch);
    printf("Small letter: %c\n", ch + 32);
}

// 1.8 Convert small letter to capital letter
void program1_8() {
    char ch;
    printf("Enter a small letter: ");
    scanf(" %c", &ch);
    printf("Capital letter: %c\n", ch - 32);
}

// 1.9 Sum of first and last digit of 3-digit number
void program1_9() {
    int n;
    printf("Enter a 3-digit number: ");
    scanf("%d", &n);
    int first = n / 100;
    int last = n % 10;
    printf("Sum = %d\n", first + last);
}

// 1.10 Reverse two-digit number
void program1_10() {
    int n;
    printf("Enter a two-digit number: ");
    scanf("%d", &n);
    int rev = (n % 10) * 10 + (n / 10);
    printf("Reverse = %d\n", rev);
}

// 1.11 Find maximum of three numbers
void program1_11() {
    int a, b, c;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);
    int max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    printf("Maximum = %d\n", max);
}

// 1.12 Swap using third variable
void program1_12() {
    int a, b, temp;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    temp = a; a = b; b = temp;
    printf("After swap: a=%d b=%d\n", a, b);
}

// 1.13 Swap without third variable
void program1_13() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    a = a + b;
    b = a - b;
    a = a - b;
    printf("After swap: a=%d b=%d\n", a, b);
}

// 1.14 Celsius to Fahrenheit
void program1_14() {
    float c;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &c);
    printf("Fahrenheit = %.2f\n", (c * 9 / 5) + 32);
}

// 1.15 Check even or odd
void program1_15() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    if (n % 2 == 0) printf("Even\n");
    else printf("Odd\n");
}

// 1.16 Average value of items
void program1_16() {
    float w1, w2, n1, n2;
    printf("Enter weight and quantity of item1: ");
    scanf("%f %f", &w1, &n1);
    printf("Enter weight and quantity of item2: ");
    scanf("%f %f", &w2, &n2);
    float avg = ((w1 * n1) + (w2 * n2)) / (n1 + n2);
    printf("Average value = %.2f\n", avg);
}

// 1.17 Employee salary calculation
void program1_17() {
    int emp_id;
    float hours, rate;
    printf("Enter employee ID: ");
    scanf("%d", &emp_id);
    printf("Enter total hours worked: ");
    scanf("%f", &hours);
    printf("Enter amount per hour: ");
    scanf("%f", &rate);
    printf("Employee ID: %d\nSalary = %.2f\n", emp_id, hours * rate);
}

// 1.18 Leap year check
void program1_18() {
    int year;
    printf("Enter a year: ");
    scanf("%d", &year);
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
        printf("Leap year\n");
    else
        printf("Not a leap year\n");
}

// 1.19 Convert days into years, weeks and days
void program1_19() {
    int days;
    printf("Enter number of days: ");
    scanf("%d", &days);
    int years = days / 365;
    int weeks = (days % 365) / 7;
    int rem_days = (days % 365) % 7;
    printf("%d years, %d weeks, %d days\n", years, weeks, rem_days);
}

// 1.20 Distance between two points
void program1_20() {
    float x1, y1, x2, y2;
    printf("Enter coordinates of point1 (x1 y1): ");
    scanf("%f %f", &x1, &y1);
    printf("Enter coordinates of point2 (x2 y2): ");
    scanf("%f %f", &x2, &y2);
    float dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    printf("Distance = %.2f\n", dist);
}

int main() {
    program1_1();
    program1_2();
    program1_3();
    program1_4();
    program1_5();
    program1_6();
    program1_7();
    program1_8();
    program1_9();
    program1_10();
    program1_11();
    program1_12();
    program1_13();
    program1_14();
    program1_15();
    program1_16();
    program1_17();
    program1_18();
    program1_19();
    program1_20();

    return 0;
}