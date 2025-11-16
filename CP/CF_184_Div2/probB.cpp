#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        bool isInfinite = false;
        for (int i = 0; i < (int)s.size() - 1; i++) {
            if (s[i] != '<' && s[i + 1] != '>') { //all cases != '< >' goes infinity
                cout << -1 << "\n";
                isInfinite = true;
                break;
            }
        }
        if (!isInfinite) {
            int left = count(s.begin(), s.end(), '<');
            int right = count(s.begin(), s.end(), '>');
            cout << (int)s.size() - min(left, right) << "\n";
        }
    }
    return 0;
}
