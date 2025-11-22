#include <stdio.h>
#include <string.h>

struct students {
    int roll;
    char name[100];
    int marks_in_physics, marks_in_chemistry, marks_in_mathematics;
    int total;
} s[3];

int n = 3;

void swapStruct(struct students *a, struct students *b) {
    struct students temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    for (int i = 0; i < n; i++) {
        printf("For Student %d\n", i + 1);
        printf("Enter roll, name, marks in phy, chem, maths \n");
        scanf("%d %s %d %d %d",
              &s[i].roll, s[i].name,
              &s[i].marks_in_physics,
              &s[i].marks_in_chemistry,
              &s[i].marks_in_mathematics);

        s[i].total = s[i].marks_in_physics +
                     s[i].marks_in_chemistry +
                     s[i].marks_in_mathematics;
    }

    // Bubble sort on total marks
    for (int i = 0; i < n - 1; i++) {
        int didSwap = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j].total > s[j + 1].total) {
                swapStruct(&s[j], &s[j + 1]);
                didSwap = 1;
            }
        }
        if (!didSwap) break;
    }

    printf("\nRanklist:\n");
    printf("Rank\tRoll No.\tName\tTotal Marks\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%s\t%d\n",
               i + 1, s[i].roll, s[i].name, s[i].total);
    }
}
