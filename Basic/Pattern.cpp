#include <bits/stdc++.h>

using namespace std; 

void print1(int n){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <=i; j++)
        {
            cout<<j<<" "; 
        }
        cout<<endl; 
    }
}

void print2(int n){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <=i; j++)
        {
            cout<<i<<" "; 
        }
        cout<<endl; 
    }
}

void print3(int n){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 5, ch = 1; j >=i; ch++,j--)
        {
            cout<<ch<<" "; 
        }
        cout<<endl; 
    }
}

void print4(int n){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <=n-i; j++)
            cout<<" "; 
        for (int k = 1; k <=2*i-1; k++)
            cout<<"#"; 
        // for (int l = 1; l <=n-i; l++)
        //     cout<<" "; 
        cout<<endl; 
    }
}

void print5(int n){
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <=n-i; j++)
            cout<<" "; 
        for (int k = 1; k <=2*i-1; k++)
            cout<<"#"; 
        // for (int l = 1; l <=n-i; l++)
        //     cout<<" "; 
        cout<<endl; 
    }
}

void print6(int n){
    for (int i = 1; i <n; i++)
    {
        for (int j = 1; j <=n-i; j++)
            cout<<" "; 
        for (int k = 1; k <=2*i-1; k++)
            cout<<"#"; 
        // for (int l = 1; l <=n-i; l++)
        //     cout<<" "; 
        cout<<endl; 
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <=n-i; j++)
            cout<<" "; 
        for (int k = 1; k <=2*i-1; k++)
            cout<<"#"; 
        // for (int l = 1; l <=n-i; l++)
        //     cout<<" "; 
        cout<<endl; 
    }
}

void print7(int n){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <=n-i; j++)
            cout<<" "; 
        for (int k = 1, ch = 65; k <=2*i-1; k++){
            cout<<(char)ch; 
            if(k<=(2*i-1)/2) 
                ch++;
            else 
                ch--; 
        }
        cout<<endl; 
    }
}
int main(){
    print1(5); 
    print2(9); 
    print3(5); 
    print4(5); 
    print5(5); 
    print6(5); 
    print7(5); 
}

