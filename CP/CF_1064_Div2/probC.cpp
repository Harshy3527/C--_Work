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
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        long long total = 0, maxi = a[0];
        for (int i = 0; i < n; ++i) {
            total += max(a[i], a[(i + 1) % n]); 
            if (a[i] > maxi) maxi = a[i];           
        }
        cout <<total - maxi<<endl;
    }
    return 0;
}
