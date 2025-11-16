#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        vector<ll> a(n);
        ll X = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            X ^= a[i];
        }
        while(q--){
            ll c;
            cin >> c;
            ll d = c ^ X;
            cout << d << "\n";
        }
    }
    return 0;
}
