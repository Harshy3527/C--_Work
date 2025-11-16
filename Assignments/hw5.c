#include <stdio.h>
#include <string.h>
void prog511(){
    int arr[3][3]; 
    //input into matrix
    for(int i =0; i<3; i++){
        printf("Enter the elements in row %d : ", i+1); 
        for(int j =0; j<3; j++){
            scanf("%d", &arr[i][j]); 
        }
    }
    //printing the matrix
    for(int i =0; i<3; i++){
        for(int j =0; j<3; j++)
            printf("%d ", arr[i][j]); 
        putchar('\n'); 
    }
}

void prog512(){
    int rows, cols; 
    printf("Enter the rows and cols: "); 
    scanf("%d %d", &rows, &cols); 

    int A[rows][cols], B[rows][cols], res[rows][cols]; 

    printf("Enter the elements for Matrix A:\n"); 
    for(int i = 0; i < rows; i++){
        printf("Enter for row %d: ", i+1); 
        for(int j = 0; j < cols; j++)
            scanf("%d", &A[i][j]); 
    }

    printf("Enter the elements for Matrix B:\n"); 
    for(int i = 0; i < rows; i++){
        printf("Enter for row %d: ", i+1); 
        for(int j = 0; j < cols; j++)
            scanf("%d", &B[i][j]); 
    }

    // Addition
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            res[i][j] = A[i][j] + B[i][j]; 

    // Printing
    printf("Resultant Matrix (A + B):\n");
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++)
            printf("%d ", res[i][j]); 
        putchar('\n'); 
    }
}


void prog513(){
    int r1, c1, r2, c2; 
    printf("Enter rows and cols of Matrix A: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and cols of Matrix B: ");
    scanf("%d %d", &r2, &c2);

    if(c1 != r2){ 
        printf("Multiplication not possible.\n"); 
        return; 
    }

    int A[r1][c1], B[r2][c2], C[r1][c2];

    printf("Enter elements of Matrix A:\n");
    for(int i = 0; i < r1; i++){
        printf("Enter row %d: ", i+1);
        for(int j = 0; j < c1; j++)
            scanf("%d", &A[i][j]);
    }

    printf("Enter elements of Matrix B:\n");
    for(int i = 0; i < r2; i++){
        printf("Enter row %d: ", i+1);
        for(int j = 0; j < c2; j++)
            scanf("%d", &B[i][j]);
    }

    // Initialize result matrix
    for(int i = 0; i < r1; i++)
        for(int j = 0; j < c2; j++)
            C[i][j] = 0;

    // Multiplication
    for(int i = 0; i < r1; i++)
        for(int j = 0; j < c2; j++)
            for(int k = 0; k < c1; k++)
                C[i][j] += A[i][k] * B[k][j];

    // Output
    printf("Resultant Matrix (A x B):\n");
    for(int i = 0; i < r1; i++){
        for(int j = 0; j < c2; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }
}

void prog514(){ 
    int i=0; 
    char str[] = {"Hi I am Harshit !"}; 
    while(str[i]!='\0') i++; 
    printf("Length of string = %d", i); 
}

void prog515(){
    char str[] = {"I am "}, str1[]= {"Harshit"}; 
    int len1 = (sizeof(str)-1), len2 = sizeof(str1)-1;
    char strnew[len1+len2+1]; //+1 for null character
    for(int i =0,k=0; i<=len1+len2; i++){
        if(i<len1) 
            strnew[i] = str[i];
        else 
            strnew[i] = str1[k++];
    }
    int i=0; 
    while(strnew[i]!='\0') printf("%c", strnew[i]), i++; 
}

void prog516(){
    char str[] = {"Hi I am Harshit !"};
    printf("%d", strlen(str)); 
    char revStr[strlen(str)]; 
    for(int i =0; i<=strlen(str); i++){
        revStr[i] = str[strlen(str)-i]; 
    }
    int i =0; 
    printf("%s", revStr);  

}
//     printf("%d", len);
//     printf("%s", str);  
//     for(int i =0; i<len/2; i++){
//         char temp = str[i]; 
//         str[i] = str[len-1]; 
//         str[len-1] = temp; 
//     }
//     printf("%s", str); 
//     int i =0;
//     while(str[i]!='\0') printf("%c", str[i]), i++;  
// }
int main(){
    // prog511();
    prog512();  
    prog513();

}