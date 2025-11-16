#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
int main(){
    int t; 
    cin>>t; 
    while(t--){
        int n; 
        cin>>n; 
        vector<ll> a(n+1); 
        for(int i =1; i <= n; i++)
            cin >> a[i];
        vector<ll> p1(n+1), p2(n+1);
        ll pref =0; 
        for(ll i= 1; i <= n; i++){
            p1[i] = pref - i * i + i;
            pref += a[i]; 
            p2[i] = (i * i + i -pref); 
        }

        ll mx = p1[1], ans = 0;
        for(int i =1; i<=n; i++){
            mx = max(mx, p1[i]);
            ans = max(ans, p2[i]+mx);
        }

        ans += accumulate(all(a), 0ll);
        cout<< ans << "\n";
    }
}