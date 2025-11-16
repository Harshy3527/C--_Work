#include <bits/stdc++.h>
using namespace std;

void recBubbleSort(int arr[], int n) {
    if (n == 1) return; //base case
    int didSwap = 0;
    for (int j = 0; j <= n - 2; j++) {
        if (arr[j] > arr[j + 1]) {
            int temp = arr[j + 1];
            arr[j + 1] = arr[j];
            arr[j] = temp;
            didSwap = 1;
        }
    }
    if (didSwap == 0) return; // if no swapping happens.
    recBubbleSort(arr, n - 1); //max element bubble to right, so work on n-1 element now 
}

int main() {
    int n, i = 0;
    cout << "How many numbers?" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the numbers\n";
    while (i != n) cin >> arr[i++];
    recBubbleSort(arr, n);
}