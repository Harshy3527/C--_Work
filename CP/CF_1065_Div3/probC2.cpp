#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> a(n+1), b(n+1);

        int XA = 0, XB = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            XA ^= a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
            XB ^= b[i];
        }

        if (XA == XB) {
            cout << "Tie\n";
            continue;
        }

        int S = XA ^ XB;

        int hb = 0;
        for (int bit = 0; bit < 31; bit++) {
            if (S & (1 << bit))
                hb = bit;
        }

        int last = -1;
        for (int i = n; i >= 1; i--) {
            int x = a[i] ^ b[i];
            if (x & (1 << hb)) {
                last = i;
                break;
            }
        }

        if (last % 2 == 1)
            cout << "Ajisai\n";
        else
            cout << "Mai\n";
    }

    return 0;
}
