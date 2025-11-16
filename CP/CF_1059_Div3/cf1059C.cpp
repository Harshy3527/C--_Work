#include <bits/stdc++.h>
using namespace std;

int msb(int x) {
    for (int i = 30; i >= 0; i--)
        if (x & (1 << i)) 
	   return i;
    return -1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        if (a == b) {
            cout << 0 << "\n";
            continue;
        }

        if (msb(b) > msb(a)) {
            cout << -1 << "\n";
            continue;
        }

        int x = a ^ b;
        vector<int> diffBits;

        for (int i = 0; i <= 30; i++) {
            if (x & (1 << i)) {
                if ((1 << i) <= a)
                    diffBits.push_back(1 << i);
                else {
                    diffBits.clear();
                    break;
                }
            }
        }

        if (diffBits.empty()) {
            cout << -1 << "\n";
        } else {
            cout << diffBits.size() << "\n";
            for (int x : diffBits) cout << x << " ";
            cout << "\n";
        }
    }
    return 0;
}
