#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n; 
        vector<long long> a(n);
        for (auto &x : a) cin >> x;

        sort(a.begin(), a.end());

        // Check if polygon is possible at all
        long long total = accumulate(a.begin(), a.end(), 0LL);
        if (a.back() >= total - a.back()) {
            cout << 0 << '\n';
            continue;
        }

        // Count frequencies
        unordered_map<long long, int> freq;
        for (auto x : a) freq[x]++;

        long long base = 0;
        vector<long long> odd, even;

        // Form as many pairs as possible
        for (auto [x, c] : freq) {
            base += x * 1LL * (c / 2);
            if (c % 2) odd.push_back(x);
            if (c >= 2) even.push_back(x);
        }

        if (base == 0) {
            cout << 0 << '\n';
            continue;
        }

        long long ans = 0;
        sort(odd.begin(), odd.end());

        // Try one odd side
        for (auto x : odd)
            if (2 * base > x)
                ans = max(ans, 2 * base + x);

        // Try two odd sides
        for (int i = 1; i < (int)odd.size(); i++)
            if (odd[i - 1] + 2 * base > odd[i])
                ans = max(ans, odd[i - 1] + 2 * base + odd[i]);

        // Try using an even side set
        for (auto x : even)
            if (base - x > 0)
                ans = max(ans, 2 * base);

        cout << ans << '\n';
    }
}
