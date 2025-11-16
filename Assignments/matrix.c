#include <stdio.h>

void inputMatrix(int mat[10][10], int r, int c) {
    printf("Enter elements (%d x %d):\n", r, c);
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &mat[i][j]);
}

void printMatrix(int mat[10][10], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

void addMatrix(int A[10][10], int B[10][10], int r, int c) {
    int sum[10][10];
    printf("\nSum of matrices:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            sum[i][j] = A[i][j] + B[i][j];
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrix(int A[10][10], int B[10][10], int r1, int c1, int r2, int c2) {
    if (c1 != r2) {
        printf("\nMatrix multiplication not possible.\n");
        return;
    }

    int C[10][10] = {0};
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            for (int k = 0; k < c1; k++)
                C[i][j] += A[i][k] * B[k][j];

    printf("\nProduct of matrices:\n");
    printMatrix(C, r1, c2);
}

int main() {
    int A[10][10], B[10][10];
    int r1, c1, r2, c2;

    printf("Enter rows and columns of Matrix A: ");
    scanf("%d %d", &r1, &c1);
    inputMatrix(A, r1, c1);

    printf("\nEnter rows and columns of Matrix B: ");
    scanf("%d %d", &r2, &c2);
    inputMatrix(B, r2, c2);

    printf("\nMatrix A:\n");
    printMatrix(A, r1, c1);

    printf("\nMatrix B:\n");
    printMatrix(B, r2, c2);

    // Addition possible only if sizes match
    if (r1 == r2 && c1 == c2)
        addMatrix(A, B, r1, c1);
    else
        printf("\nMatrix addition not possible (different dimensions).\n");

    // Multiplication check
    multiplyMatrix(A, B, r1, c1, r2, c2);

    return 0;
}
