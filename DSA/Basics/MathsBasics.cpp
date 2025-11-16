#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter a number ";
    cin >> n;
    int digit, count = 0, no;

    cout << ((int)(log10(n)) + 1) << endl; // better method for counting digits

    while (n > 0){       // BIG O(log10(n))
        digit = n % 10; // helpful in digit extraction
        count++;
        n /= 10;
    }

    no = count;
    cout << no << endl;
}

vector<int> findDivisors(int n)
{
    // Initialize an empty
    // vector to store the divisors
    vector<int> divisors;
    for (int i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            // Add divisor i to the list
            divisors.push_back(i);

            // Add the counterpart divisor
            // if it's different from i
            if (i != n / i)
            {
                // Add the counterpart
                // divisor to the list
                divisors.push_back(n / i);
            }
        }
    }
    return divisors;
}

int findGcd1(int n1, int n2) {     //O(min(N1,N2))
    int gcd = 1;
    for(int i = 1; i <= min(n1, n2); i++) {
        if(n1 % i == 0 && n2 % i == 0)
            gcd = i;
    }
    return gcd;
}

int findGcd(int n1, int n2) { // O(min(n1,n2)) but its average will be faster
    // Start from the minimum of n1 and n2 because the GCD cannot exceed the smaller number
    for(int i = min(n1, n2); i > 0; i--) {
        if(n1 % i == 0 && n2 % i == 0)
            return i;
    }
    return 1;
}


int findGcd(int a, int b) { // Euclidean Algorithm - best approach 
                           //O(phi)(log(min(n1,n2)))
    while (a > 0 && b > 0){
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }
    if (a == 0)
        return b;
    return a;
}


