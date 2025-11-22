#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) cin >> b[i];
        int xorA = 0, xorB = 0;
        for (int i = 1; i <= n; ++i) {
            xorA ^= a[i];
            xorB ^= b[i];
        }
        if (xorA == xorB) {
            cout << "Tie\n";
            continue;
        }
        int last_diff = -1;
        for (int i = n; i >= 1; --i) {
            if (a[i] != b[i]) {
                last_diff = i;
                break;
            }
        }
        if (last_diff % 2 == 1)
            cout << "Ajisai\n";
        else
            cout << "Mai\n";
    }
    return 0;
}
