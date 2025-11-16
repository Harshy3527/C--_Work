#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    k %= n; //min no of reversals required

    // Step 1: reverse first k elements
    reverse(arr.begin(), arr.begin() + k);

    // Step 2: reverse remaining n - k elements
    reverse(arr.begin() + k, arr.end());

    // Step 3: reverse whole array
    reverse(arr.begin(), arr.end());
    for (int x : arr) cout << x << " ";
}
