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
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a.rbegin(), a.rend()); // sort descending for easy pairing

        vector<int> pairs; // store stick lengths used in pairs
        int leftover = -1;

        unordered_map<int, int> freq;
        for (int x : a) freq[x]++;

        for (auto it = freq.begin(); it != freq.end(); it++) {
            int cnt = it->second;
            int len = it->first;
            while (cnt >= 2) {
                pairs.push_back(len);
                cnt -= 2;
            }
            if (cnt == 1 && leftover == -1) leftover = len;
        }

        if (pairs.size() == 0) { // no pairs → cannot form symmetric polygon
            cout << 0 << "\n";
            continue;
        }

        // build the polygon
        vector<int> polygon;
        for (int len : pairs) polygon.push_back(len);
        for (int i = pairs.size() - 1; i >= 0; i--) polygon.push_back(pairs[i]);
        if (leftover != -1) {
            polygon.insert(polygon.begin() + pairs.size(), leftover);
        }

        // check convexity: largest side < sum of others
        int max_side = *max_element(polygon.begin(), polygon.end());
        long long sum_others = 0;
        for (int x : polygon) sum_others += x;
        sum_others -= max_side;

        if (max_side >= sum_others) cout << 0 << "\n";
        else {
            long long perimeter = accumulate(polygon.begin(), polygon.end(), 0LL);
            cout << perimeter << "\n";
        }
    }
}
