#include <bits\stdc++.h>
using namespace std; 

int main(){
    short X = 0,n; 
    cin>>n; string op; 
    while(n--){
        cin>>op; 
        if(op =="X++"||op=="++X") X++; 
        else if(op=="X--"||op=="--X") X--;
    }
    cout<<X; 
}