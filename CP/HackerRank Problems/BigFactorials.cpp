#include <bits/stdc++.h>
using namespace std;

void extraLongFactorials(int n) {
    vector<int> result(3000, 0); 
    result[0] = 1; 
    int size = 1;

    for (int x = 2; x <= n; x++) {
        int carry = 0;
        for (int i = 0; i < size; i++) {
            long long val = result[i] * 1LL * x + carry;
            result[i] = val % 10;
            carry = val / 10;
        }
        while (carry) {
            result[size] = carry % 10;
            carry /= 10;
            size++;
        }
    }

    for (int i = size - 1; i >= 0; i--)
        cout << result[i];
    cout << "\n";
}

int main() {
    int n;
    cin >> n;
    extraLongFactorials(n);
    return 0; 
}
