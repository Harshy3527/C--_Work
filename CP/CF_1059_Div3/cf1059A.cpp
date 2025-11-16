#include<bits\stdc++.h>
using namespace std; 

int main(){
    int t; 
    cin>>t; 
    while(t--){
        int n,j; //length of arr
        cin>>n; 
        int arr[n]; 
        for(int i =0; i<n; i++)
            cin>>arr[i];
        sort(arr, arr+n, greater<int>()); 
        float avg=0, max=INT_MIN;
        for(int i =0; i<n; i++){
            float s=0; int k=0;
            for(j=0; j<=i; j++){
                s+=arr[j];k++ ;
            }
            avg = s/k;
            if(avg>=max) max = avg;
        }
        cout<<max;
    }
}