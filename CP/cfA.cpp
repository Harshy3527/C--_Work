#include <bits/stdc++.h>
using namespace std;

int main() {
    string x;
    cin >> x;
    for (int i = 0; i < x.size(); i++) {
        int digit = x[i] - '0';
        if (i == 0 && digit == 9) continue; // first digit stays 9
        if (digit >= 5) digit = 9 - digit;
        x[i] = digit + '0'; //ascii 
    }
    cout << x;
}
