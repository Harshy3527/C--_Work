#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> p(n+1);
        for(int i = 1; i <= n; i++){
            cin >> p[i];
        }
        vector<int> pre(n+1), suf(n+2);
        pre[1] = p[1];
        for(int i = 2; i <= n; i++){
            pre[i] = min(pre[i-1], p[i]);
        }
        suf[n] = p[n];
        for(int i = n-1; i >= 1; i--){
            suf[i] = max(suf[i+1], p[i]);
        }
        bool ok = true;
        for(int i = 2; i <= n; i++){
            if(pre[i-1] > suf[i]){
                ok = false;
                break;
            }
        }
        cout << (ok ? "Yes\n" : "No\n");
    }
    return 0;
}
