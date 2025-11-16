#include <bits\stdc++.h>
using namespace std;

void insertionSort(int arr[], int n) {
  int j;
  for (int i = 0; i <= n - 1; i++) {
    j = i;
    while (j > 0 && arr[j] < arr[j-1]) { 
      int temp = arr[j - 1];
      arr[j - 1] = arr[j];
      arr[j] = temp;
      j--; 
    }
  }
}                                                   
 
int main() {
  int n, i = 0;
  cout << "How many numbers?" << endl;
  cin >> n;
  int arr[n];
  cout << "Enter the numbers\n";
  while (i != n) cin >> arr[i++];
  insertionSort(arr, n);
}