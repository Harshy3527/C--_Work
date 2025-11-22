#include <bits\stdc++.h>
using namespace std;

void sortNPrint(int arr[], int n) {
  for (int i = n-1; i >= 0; i--) { 
    int didSwap =0; 
    for (int j = 0; j <= i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        didSwap++; 
      }
    }
    if(didSwap==0) break; 
  }
  cout << "Sorted Array :-" << endl;
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
}

int main() {
  int n, i = 0;
  cout << "How many numbers?" << endl;
  cin >> n;
  int arr[n];
  cout << "Enter the numbers\n";
  while (i != n) cin >> arr[i++];
  sortNPrint(arr, n);
}