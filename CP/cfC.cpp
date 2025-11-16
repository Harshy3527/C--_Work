#include <bits\stdc++.h>
using namespace std;

int main() {
  int t, n;
  cin >> t;

  //test cases
  for (int i = 1; i <= t; i++) {
    cin >> n;
    int sides[n];

    //input sides
    for (int i = 0; i < n; i++) {
      cin >> sides[i];
    }

    sort(sides, sides + n);
    int s = 0, cPair = 0, j = 0, left = INT32_MIN, sum = 0;
    
    while (j < n - 1) {
      if (sides[j] == sides[j + 1]) {
        cPair++;
        s += (sides[j] * 2);
        j += 2; 
      } else if(cPair!=0){
        cout<<0<<endl; continue; 
      }
      else {
        left = (sides[j] >= left) ? sides[j] : left;
        j++;
      } 
    }

    s = (left != INT32_MIN) ? s + left : s;
    cout << s;
  }
}