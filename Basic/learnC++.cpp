#include <iostream>      // for using basic i/o functions
#include<bits/stdc++.h> //includes all libraries.
using namespace std;

//single pass compilation 
//forward declaration

string getAdultStatus(int age){
    if(age>=18)
        return "You're an Adult"; 
    else
        return "Not an Adult"; 
}

// int[] is not a valid return type in C++

// int[] printMarks(){
//     int marks[] = {99,100,99,100,99}; 
//     return marks; 
// }

vector<int> printMarks(){
    return {99,100,99,100,99};
}


int main() {
    vector<int> marks = printMarks(); //can't directly print an vec or an array, so 
    cout << "Marks: ";
    for(int m : marks)
        cout << m << " ";
    cout<<endl;
    cout << "Hey Everyone\n";
    cout << "Hey guy! " << endl; 
    cout << "Hello World ! Hahahaha\n"; 
    
    int x, y; 
    cout << "Enter two integers: "; // prompt user
    cin >> x >> y; 
    cout << "Value of x: " << x << " and y: " << y << endl;
    
    string s1; 
    string s2; 
    cout<<"Enter two strings\n"; 
    cin>> s1 >> s2; 
    cout << s1<< " "<<s2; 

    getline(cin, s1); //joins all strings along with spaves until a linebreak is entered
    cout <<s1; 
    int age; 
    cout<<"Enter age : "; 
    cin>>age;
    cout << getAdultStatus(age); 
    return 0; 
}


