#include <bits/stdc++.h>
using namespace std; 

void unionSet(vector<int>&nums1,vector<int>&nums2, int n1, int n2){
    set<int> st; 
    for(int x:nums1) st.insert(x); 
    for(int x:nums2) st.insert(x); 
    for(auto it: st)cout<<it<<" "; 
}

void Union(){}
int main() {
    int n1,n2, i = 0;
    cout << "How many numbers n1 and n2?" << endl;
    cin >> n1>>n2;
    vector<int> arr1(n1), arr2(n2); 
    cout << "Enter the numbers\n";
    while (i != n1) cin >> arr1[i++];
    while (i != n2) cin >> arr2[i++];
    unionSet(arr1, arr2, n1, n2); 
    return 0; 
}