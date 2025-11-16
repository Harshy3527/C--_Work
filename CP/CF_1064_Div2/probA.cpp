#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while (t--) {
        int n; 
        string s;
        cin >> n >> s;
        char last = s.back();
        int cntLast = count(s.begin(), s.end(), last);
        cout << (n - cntLast) << '\n';
    }
    return 0;
}
