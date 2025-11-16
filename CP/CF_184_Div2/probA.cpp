#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        long long a;
        cin >> n >> a;

        vector<long long> v(n);
        for(long long &x : v) cin >> x;

        int L = 0, R = 0;
        for(int i = 0; i < n; i++){
            if(v[i] < a) L++;
            else if(v[i] > a) R++;
        }

        if(L == R){
            cout << a << "\n"; //any b, cannot win
            continue;
        }

        if(L>R){
            cout<<a-1<<endl; 
        }
        else cout<<a+1<<endl;
    }
}
