#include <bits/stdc++.h>
using namespace std;

//Integer Array Hashing 
//inside main -> int[] - 10^6 || bool[] - 10^7
//globally --> int[] - 10^7 || bool[] - 10^6 
//O(N)
int main() {
    int n; //size of array
    cout<<"Enter the size of array\n"; 
    cin >> n;
    int arr[n];
    cout<<"Enter the elements"<<endl; 
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //precompute:
    int hash[13] = {0};  //12 is the largest no. i wanna hash
    for (int i = 0; i < n; i++) {
        hash[arr[i]] += 1;  //go to the num that you got, and ++ its freq
    }
    cout<<"Enter the no of queries\n"; 
    int q;  //no. of elements to hash
    cin >> q;
    cout<<"Enter the queries\n"; 
    while (q--) {
        int number;
        cin >> number;
        // fetching:
        cout <<number<<" -> "<< hash[number] << endl;
    }
    return 0;
}