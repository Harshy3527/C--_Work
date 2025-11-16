#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(const string &s) {
    int n = s.size();
    for (int i = 0; i < n/2; i++)
        if (s[i] != s[n-1-i])
            return false;
    return true;
}

bool isAscending(const string &s) {
    for (int i = 1; i < s.size(); i++)
        if (s[i] < s[i-1])
            return false;
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        bool found = false;
        for (int mask = 0; mask < (int)pow(2,n); mask++) {
            string p = "", x = "";
            vector<int> indices;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    p += s[i];
                    indices.push_back(i+1); 
                } 
                else 
                    x += s[i];
            }
            if (isAscending(p) && isPalindrome(x)) {
                cout << p.size() << "\n";
                for (int x : indices) cout << x << " ";
                cout << "\n";
                found = true;
                break;
            }
        }
        if (!found) cout << -1 << "\n";
    }
    return 0;
}
