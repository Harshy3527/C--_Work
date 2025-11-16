#include <bits\stdc++.h>    
using namespace std; 

bool stringRecursivePalindrome(const string& str, int i) {
    if (i >= (str.length()) / 2)
        return true;
    if (str[i] != str[str.length() - 1 - i])
        return false;
    return stringRecursivePalindrome(str, i + 1);
}

int main() {
    string str1 = "mom", str2 = "Harshit";
    cout << str1 << (stringRecursivePalindrome(str1, 0) ? " is" : " is not") << " a palindrome." << endl;
    cout << str2 << (stringRecursivePalindrome(str2, 0) ? " is" : " is not") << " a palindrome." << endl;
}