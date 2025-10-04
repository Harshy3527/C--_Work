#include <bits/stdc++.h>
using namespace std;

//Integer Array Hashing 
//inside main -> int[] - 10^6 || bool[] - 10^7
//globally --> int[] - 10^7 || bool[] - 10^6 
//O(N)
int main() {
    int n; //size of array
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //precompute:
    int hash[13] = {0};  //12 is the largest no. i wanna hash
    for (int i = 0; i < n; i++) {
        hash[arr[i]] += 1;  //go to the num that you got, and ++ its freq
    }

    int q;  //no. of elements to hash
    cin >> q;
    while (q--) {
        int number;
        cin >> number;
        // fetching:
        cout << hash[number] << endl;
    }
    return 0;
}