#include <stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void ArrayPointer(int a[0], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    double avg = (double)sum / n;
    printf("Sum = %d\nAverage = %lf", sum, avg);
}

void myStrLen(char *s) {
    int len = 0, i = 0;
    while (s[i++] != '\0')
        len++;
    printf("Length = %d", len);
}

void myStrCopy(char *s) {
    char copy[100];
    int i = 0;
    while (s[i]) {
        copy[i] = s[i];
        i++;
    }
    printf("%s\n%s", copy);
}

void my_strrev(char *s[]) {
    int i = 0, j = my_strlen(s) - 1, t;
    while (i < j) {
        t = s[i];
        s[i] = s[j];
        s[j] = t;
        i++;
        j--;
    }
}

void ArrayPointer2(int *a[], int *n) {
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    printf("Max = %d", max);

    int min = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] < min)
            min = a[i];
    printf("Max = %d", min);
}

void countVowel(char *s[]) {
    int i = 0, len = my_strlen(s), vowel =0;
    for (int i = 0; i < len; i++) {
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
            vowel++; 
    }
    printf("No. of Vowels = %d\nNo. of Consonants = %d", vowel, (len-vowel)); 
}

void ArrayPointer(int array[], int *n){
    for(int i =0; i<n; i++)         {

    }
}
int main() {
    int choice;
    printf("Enter choice : ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
        int n1, n2;
        scanf("%d %d", &n1, &n2);
        printf("Before Swapping - %d %d\n", n1, n2);
        swap(&n1, &n2);
        printf("After Swapping - %d %d", n1, n2);
        break;

    case 2:
        int arr[100];
        printf("Enter the no of elements : ");
        int n;
        scanf("%d", &n);
        printf("Enter the elements : ");
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        ArrayPointer(arr, n);
        break;
    case 3:
        char s1[100];
        printf("Enter a string : ");
        getchar();
        gets(s1);
        myStrLen(s1);
        break;
    case 4:
        char s2[100];
        printf("Enter a string :");
        getchar();
        gets(s2);
        myStrCopy(s2);
        break;
    case 5:
        char s3[100];
        printf("Enter a string :");
        getchar();
        gets(s3);
        my_strrev(s3);
        break;

    case 6:
        int arr2[100];
        printf("Enter the no of elements : ");
        int num;
        scanf("%d", &num);
        printf("Enter the elements : ");
        for (int i = 0; i < num; i++) {
            scanf("%d", &arr2[i]);
        }
        ArrayPointer2(arr2, &num);
        break;

    case 7:
        char s4[100];
        printf("Enter a string : ");
        getchar();
        gets(s4);
        countVowel(s4);
        break;
    case 8 :
    int array[100];
    printf("Enter the no of elements : ");
    int length;
    scanf("%d", &length);
    printf("Enter the elements : ");
    for (int i = 0; i < length; i++) {
        scanf("%d", &array[i]);
    }
    ArrayPointer3(array, *length); 
    }
}