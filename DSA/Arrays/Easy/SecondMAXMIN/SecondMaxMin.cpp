#include <bits/stdc++.h>
using namespace std;

int secondMax(int arr[], int n){
    int largest = INT_MIN, secMax = INT_MIN;

    for(int i = 0; i < n; i++){
        if(arr[i] > largest){
            secMax = largest;
            largest = arr[i];
        } else if(arr[i] > secMax && arr[i] != largest){ //if 1st element was largest 
            secMax = arr[i];
        }
    }
    return secMax;
}

int secondMin(int arr[], int n){
    int smallest = INT_MAX, secMin = INT_MAX;

    for(int i = 0; i < n; i++){
        if(arr[i] < smallest){
            secMin = smallest;
            smallest = arr[i];
        } else if(arr[i] < secMin && arr[i] != smallest){
            secMin = arr[i];
        }
    }
    return secMin;
}

int main(){
    cout << "Enter no of elements and then the elements:-" << endl;

    int n;
    cin >> n;
    int arr[n];
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "Second largest = " << secondMax(arr, n) << endl;
    cout << "Second smallest = " << secondMin(arr, n) << endl;

    return 0;
}
