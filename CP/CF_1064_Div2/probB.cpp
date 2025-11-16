#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        long long a, b, n;
        cin >> a >> b >> n;
        if (b >= a || n * b <= a) cout << 1 <<endl;
        else cout << 2 <<endl;
    }
    return 0;
}
