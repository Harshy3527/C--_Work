#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n % 2 != 0) {
            cout << 0 << endl;
            continue;
        }
        int k =0; 
        for(int b =0;b<n ;b++){
            for(int a= 0;a<n ; a++){
                if((2*a+b)==n/2) k++; 
            }
        }
        cout<<k<<endl;
    }
    return 0;
}