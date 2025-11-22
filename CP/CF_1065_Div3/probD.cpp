#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    if(!(cin>>t)) return 0;
    while(t--){
        int n; cin>>n;
        vector<int> p(n+1), pos(n+1);
        for(int i=1;i<=n;i++){
            cin>>p[i];
            pos[p[i]] = i; 
        }
        vector<int> prefMin(n+1), sufMax(n+2);
        int curMin = INT_MAX;
        for(int i=1;i<=n;i++){
            curMin = min(curMin, pos[i]);
            prefMin[i] = curMin;
        }
        int curMax = INT_MIN;
        for(int i=n;i>=1;i--){
            curMax = max(curMax, pos[i]);
            sufMax[i] = curMax;
        }
        bool ok = true;
        for(int k=1;k<=n-1;k++){
            if(prefMin[k] > sufMax[k+1]){
                ok = false;
                break;
            }
        }
        cout << (ok ? "Yes\n" : "No\n");
    }
    return 0;
}
