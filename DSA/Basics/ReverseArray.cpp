
#include <bits\stdc++.h>
using namespace std;

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 3, 4, 5};
    int arr3[] = {1, 2, 3, 4, 5};
    int n = 5;

    cout << "reverseArray:        ";
    reverseArray(arr1, n);
    cout << endl;

    cout << "reverseArray2:       ";
    reverseArray2(arr2, n);
    cout << endl;

    cout << "revRecursiveArray:   ";
    revRecursiveArray(arr3, 0, n - 1);
    printArray(arr3, n);

    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverseArray(int arr[], int n) {
    int p1 = 0, p2 = n - 1;
    while (p1 < p2) {
        swap(&arr[p1], &arr[p2]);
        p1++, p2--;
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

void reverseArray2(int arr[], int n){
    int p1 = 0, p2 = n - 1;
    while (p1 < p2) {
        int temp = arr[p1];
        arr[p1]= arr[p2]; 
        arr[p2]= temp;
        p1++, p2--;
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

void revRecursiveArray(int arr[], int p1, int p2) {
    if (p1 < p2) {
        swap(&arr[p1], &arr[p2]);
        revRecursiveArray(arr, p1 + 1, p2 - 1);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
