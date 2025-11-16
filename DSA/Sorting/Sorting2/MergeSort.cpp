#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low, right = mid + 1;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) 
            temp.push_back(arr[left++]);
        else 
            temp.push_back(arr[right++]);
    }

    while (left <= mid) temp.push_back(arr[left++]);
    while (right <= high) temp.push_back(arr[right++]);

    for (int i = low; i <= high; i++)
        arr[i] = temp[i - low];
}

void ms(vector<int>& arr, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2;
    ms(arr, low, mid);
    ms(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main() {
    int n, x;
    cout << "How many numbers? ";
    cin >> n;

    vector<int> arr;
    cout << "Enter the numbers:\n";
    for (int i = 0; i < n; i++) {
        cin >> x;
        arr.push_back(x);
    }

    ms(arr, 0, n - 1);

    cout << "Sorted array:\n";
    for (int val : arr) cout << val << " ";
    cout << endl;
    return 0;
}
