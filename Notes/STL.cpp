#include <bits/stdc++.h>
using namespace std;

namespace harsh {
int val = 50;
int getVal() { 
    return val * 10; }
} 

struct node {
  string str;
  int num;
  double doub;
  char x;

  node(string str_, int num_, double doub_, char x_) {
    str = str_;
    num = num_;
    doub = doub_;
    x = x_;
  }

};

int main() {
  double val = 10.0;
  cout << val << endl;               // prints 10
  cout << harsh ::val << endl;       // prints 50
  cout << harsh ::getVal() << endl;  // prints 500

//wrong way
//   node harshit;
//   harshit.str = "verma";
//   node* harshit = new node("Harshit Verma", 116, 99.4, '\0');
}