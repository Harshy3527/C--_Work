#include <stdio.h>

void printMatrix(int matrix[][]);
void inputMatrix(int i, int j, int matrix[i][j]);

int main(){
    int i, j; 
    printf("Enter rows and columns :- \n"); 
    scanf("%d %d", &i,&j); 
    //getting matrix
    int matrix[i][j];
    inputMatrix(i, j, matrix);
    printMatrix(matrix, i, j); 
    return 0;
}
void printMatrix(int matrix[][], int i, int j){
    //printing the matrix
    printf("The Matrix is as follows:-\n");
    for (int rows = 0; rows < i; rows++) {
        printf("[");
        for (int col = 0; col < j; col++) {
            printf("%2d", matrix[rows][col]);
            if (col < j - 1) printf(",");
        }
        printf("]\n");
    }
}
void inputMatrix(int i, int j, int matrix[i][j]) {
    for (int rows = 0; rows < i; rows++) {
        printf("Enter Elements in row %d\n", (rows + 1));
        for (int col = 0; col < j; col++) {
            scanf("%d", &matrix[rows][col]);
        }
    }
}

// A two-dimensional array is actually an array in which each element is a one-dimensional array.
// The length of an array x is the number of elements in the array, which can be obtained using x.length.
// x[0],x[1], . . . , and x[x.length-1] are arrays. 
// Their lengths can be obtained using x[0].length,x[1].length, . . . , and x[x.length-1].length.
// A two-dimensional array is a one-dimensional array in which each element is another one-dimensional array.
//  Ragged Arrays
//  int[][] triangleArray = {
//  {1, 2, 3, 4, 5},
//  {2, 3, 4, 5},
//  {3, 4, 5},
//  {4, 5},
//  {5}
//  };
//  If you don’t know the values in a ragged array in advance, but do know the sizes—say, the 
// same as before—you can create a ragged array using the following syntax:
//  int[][] triangleArray = new int[5][];
//  triangleArray[0] = new int[5];
//  triangleArray[1] = new int[4];
//  triangleArray[2] = new int[3];
//  triangleArray[3] = new int[2];
//  triangleArray[4] = new int[1];
//  You can now assign values to the array. For example,
//  triangleArray[0][3] = 50;
//  triangleArray[4][0] = 45;