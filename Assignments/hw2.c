#include <stdio.h>
#include <stdlib.h>   // * needed for exit()
#include <math.h>    

void prog21(){
    int num; 
    printf("Enter a number : "); 
    scanf("%d",&num); 
    if(num>0) printf("Positive");          // *
    else if(num<0) printf("Negative");     // *
    else printf("Zero");                   // *
}

void prog22(){
    int num; 
    printf("Enter a number : "); 
    scanf("%d", &num); 
    printf(((num%5==0)&&(num%11==0))?"It is divisible by 5 and 11":"Not divisible by 5 and 11 both"); // *
}

void prog23(){
    int num; 
    printf("Enter a number : "); 
    scanf("%d",&num); 
    printf((num%2==0)?"Even": "Odd");
}

void prog24(){
    char ch; 
    printf("Enter a character : "); 
    scanf(" %c", &ch);   // * space before %c to skip newline
    switch(ch){
        case 'a': case 'e': case 'i': case 'o': case 'u':
        case 'A': case 'E': case 'I': case 'O': case 'U': // * uppercase vowels added
            printf("It is a vowel"); 
            break; 
        default: printf("It is a consonant"); 
    }
}

void prog25(){
    int num, year;  // * added year
    printf("Enter month number 1-12: "); 
    scanf("%d", &num); 
    if(num>12||num<1){
        printf("Wrong input"); 
        exit(0); 
    }
    switch(num){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: 
            printf("It has 31 days"); 
            break; 
        case 4: case 6: case 9: case 11: 
            printf("It has 30 days"); 
            break; 
        case 2: // * handle February
            printf("Enter year: "); 
            scanf("%d",&year); 
            if((year%4==0 && year%100!=0) || (year%400==0)) printf("It has 29 days"); 
            else printf("It has 28 days"); 
            break;
    }
}

void prog26(){
    printf("Enter an amount: "); 
    int N; scanf("%d", &N); 
    int rs100, rs50, rs10, rs5, rs2, rs1; 
    rs100 = N/100; 
    N%=100; 
    rs50 = N/50; 
    N%=50; 
    rs10 = N/10; 
    N%=10; 
    rs5= N/5; 
    N%=5; 
    rs2 = N/2; 
    N%=2; 
    rs1 =N/1; 
    N%=1; 
    printf("Rs100 : %d\nRs50 : %d\nRs10 : %d\nRs5 : %d\nRs2 : %d\nRs1 : %d\n", rs100, rs50, rs10, rs5, rs2, rs1); // *
}

void prog27(){
    printf("Enter the angles of your triangle: "); 
    int a1, a2, a3; 
    scanf("%d %d %d", &a1,&a2,&a3); 
    if(a1>0 && a2>0 && a3>0 && a1+a2+a3==180) // * added positive angle check
        printf("It is a valid triangle"); 
    else 
        printf("Invalid triangle"); 
}

void prog28(){
    printf("Enter the three sides of triangle: "); 
    float a,b,c; 
    scanf("%f %f %f", &a,&b,&c); 
    if(a==b && b==c)                      // * fixed logic
        printf("Equilateral triangle"); 
    else if(a==b || a==c || b==c)         // * fixed logic
        printf("Isosceles triangle"); 
    else 
        printf("Scalene triangle"); 
}

void prog29(){
    char ch; 
    printf("Enter the character: "); 
    scanf(" %c", &ch);   // * space added
    int ascii= (int)ch; 
    if((ascii>=65&&ascii<=90)||(ascii>=97&&ascii<=122))
        printf("It is a letter"); 
    else if(ascii>=48 && ascii<=57)       // * fixed digit range
        printf("It is a digit"); 
    else
        printf("It is a special character"); 
}

void prog210(){
    char ch; 
    printf("Enter the character: "); 
    scanf(" %c", &ch);   // * space added
    int ascii= (int)ch; 
    if((ascii>=65)&&(ascii<=90))
        printf("It is an uppercase character"); 
    else if(ascii>=97 && ascii<=122)      // * fixed typo
        printf("It is a lowercase character"); 
    else 
        printf("Not a letter"); 
}

void prog211(){
    int dayNum; 
    printf("Enter the day number: "); 
    scanf("%d", &dayNum); 
    switch (dayNum){
        case 1: printf("Monday");break;
        case 2: printf("Tuesday"); break; 
        case 3: printf("Wednesday"); break; 
        case 4: printf("Thursday"); break; 
        case 5: printf("Friday"); break;
        case 6: printf("Saturday"); break; 
        case 7: printf("Sunday"); break; 
        default:printf("Wrong input"); 
    }
}

void prog212(){
    printf("Enter the principal, rate, time in years: "); 
    float P, r, n; 
    scanf("%f %f %f", &P,&r,&n); 
    float amt = P * pow(1+r, n);  // * fixed CI formula
    printf("Amount after %.2f years = %.2f", n, amt); 
}

void prog213(){
    printf("Enter the marks of Physics, Chemistry, Maths, Biology and Computer: "); 
    int p,c,m,b,comp; 
    scanf("%d %d %d %d %d", &p,&c,&m,&b,&comp); 
    float perc = (p+c+m+b+comp)/500.0 * 100;  // * cast to float
    printf("Percentage = %.2f\n", perc);      // * added newline
    if(perc>=90) printf("A"); 
    else if (perc>=80) printf("B"); 
    else if(perc>=70) printf("C"); 
    else if(perc>=60) printf("D"); 
    else if(perc>=40) printf("E"); 
    else printf("F"); 
}

void prog214(){
    float basic,hra, da; 
    printf("Enter the basic salary of employee : "); 
    scanf("%f", &basic);
    if(basic <= 10000){                     // * corrected slabs
        hra = 0.20*basic; 
        da = 0.80*basic; 
    }
    else if(basic <= 20000){                // * corrected slabs
        hra = basic*0.25; 
        da = basic*0.90; 
    }
    else{
        hra = basic*0.30; 
        da = basic*0.95; 
    }
    float grossSalary = basic +hra+da; 
    printf("Gross Salary =  %0.2f", grossSalary); 
}

void prog215(){
    int units; float amt; 
    printf("Enter the number of units used : "); 
    scanf("%d", &units); 
    if(units<=50){
        amt = 0.5*units; 
    }
    else if(units<=150){
        amt = 50*0.5+ (units-50)*0.75; 
    }
    else if(units<=250){
        amt = 50*0.5+ 100*0.75+ (units-150)*1.2; 
    }
    else{
        amt = 50*0.5+ 100*0.75+ 100*1.2+(units-250)*1.5; 
    }
    amt += amt*0.2;  // * surcharge always added
    printf("The electricity bill = %0.2f", amt); 
}

void prog216(){
    char ch;
    float n1, n2; 
    printf("Enter the two numbers : "); 
    scanf("%f %f", &n1, &n2);     // * corrected scanf format
    printf("Enter the operation (+,-, *, /): ");  
    scanf(" %c", &ch);            // * fixed missing &
    switch (ch){
        case '+': printf("Sum = %0.2f", (n1+n2));break;
        case '-': printf("Difference = %0.2f", (n1-n2));break;
        case '*': printf("Product = %0.2f", n1*n2);break;
        case '/': 
            if(n2!=0) printf("Quotient = %0.2f", n1/n2); 
            else printf("Division by zero");  // * safe division
            break; 
        default: printf("Wrong Input"); 
    }
}

void progEvenOddBitwise() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if ((num&1)==0)
        printf("Even\n");
    else
        printf("Odd\n");
}

int main(){
    // prog21();
    // prog22();
    // prog23();
    // prog24();
    // prog25();
    // prog26();
    // prog27(); 
    // prog28();
    // prog29();
    // prog210();
    // prog211();
    // prog212();
    // prog213();
    // prog214();
    // prog215();
    // prog216(); 
    // progEvenOddBitwise();
}
