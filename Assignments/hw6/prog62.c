#include <stdio.h>
int array_max(int size, int arr[]);
int array_min(int size, int arr[]); 
int main() {
    int size;
    printf("Enter size of the array : \n");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements : "); 
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]); 
    int arrMax = array_max(size, arr), arrMin = array_min(size, arr);
    printf("The max element = %d\n", arrMax);
    printf("The min element = %d\n", arrMin);
}
int array_max(int size, int arr[]) {
    int max = arr[0];
    for (int i = 1; i < arr.size; i++) {
        if (arr[i] >= max)
            max = arr[i];
    }
    return max;
}
int array_min(int size, int arr[]) {
    int min = arr[0];
    for (int i = 1; i < arr.size; i++) {
        if (arr[i] <= min)
            min = arr[i];
    }
    return min;
}