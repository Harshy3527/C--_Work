#include <bits\stdc++.h>
using namespace std;

//select min and then swap
//finger goes from 0 to n-2
//figure out the min in the remaining unsorted array only

//O(n^2)
void SelectionSort(int arr[], int n) {
  for (int i = 0; i <=n-2; i++) {
    int minIndex = i;

    for (int j = i + 1; j <= n-1; j++)
      if (arr[j] < arr[minIndex]) minIndex = j;
      
    int temp = arr[i];
    arr[i] = arr[minIndex];
    arr[minIndex] = temp;
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
  while (i != n) 
    cin >> arr[i++];
  SelectionSort(arr, n);
}
