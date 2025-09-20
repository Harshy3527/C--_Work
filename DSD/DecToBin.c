#include <stdio.h>
int main(){
    printf("Enter a Decimal Number : "); 
    int decNum; 
    scanf("%d", &decNum); 
        if (decNum == 0) {
            printf("0 in binary = 0\n");
            return 0;
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
        return 0;
}