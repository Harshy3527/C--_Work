#include <bits/stdc++.h>
using namespace std;

vector<int> rotate_vec(vector<int>& nums, int k) {
    vector<int> temp(nums.size());
    for (int i = 0; i < nums.size(); i++) {
        temp[(i + k) % nums.size()] = nums[i];
    }
    nums = temp;
    return nums;
}

int main() {
    cout << "Enter no of elements, shift and then the elements:\n";

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);           

    for (int i = 0; i < n; i++) {
        cin >> arr[i];            
    }

    cout << "Rotated Array:\n";
    rotate_vec(arr, k);           
    for (auto it : arr)
        cout << it << " ";
}
