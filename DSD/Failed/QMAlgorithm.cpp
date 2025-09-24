#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n; // number of variables
vector<int> minterms;
vector<int> dontcares;

// Convert number to binary string of length n
string toBinary(int num, int len) {
    string s = "";
    for (int i = len - 1; i >= 0; i--) {
        if ((num >> i) & 1) s += '1';
        else s += '0';
    }
    return s;
}

// Count number of 1s in a binary string
int countOnes(string s) {
    int cnt = 0;
    for (char c : s) if (c == '1') cnt++;
    return cnt;
}

// Try to merge two terms
// Return merged string if they differ by exactly 1 bit, otherwise ""
string merge(string a, string b) {
    int diff = 0;
    string res = "";
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b[i]) res += a[i];
        else {
            res += '-';
            diff++;
        }
    }
    if (diff == 1) return res;
    return "";
}

// Check if a list already contains a string
bool contains(vector<string> &list, string s) {
    for (string x : list) {
        if (x == s) return true;
    }
    return false;
}

// Convert binary string with '-' to expression (e.g. 1-0 → A C')
string toExpression(string bits) {
    string expr = "";
    char var = 'A';
    for (int i = 0; i < bits.size(); i++) {
        if (bits[i] == '1') expr += var;
        else if (bits[i] == '0') {
            expr += var;
            expr += '\'';
        }
        // if '-', skip the variable
        var++;
    }
    if (expr == "") return "1"; // covers all
    return expr;
}

int main() {
    cout << "How many variables? ";
    cin >> n;

    int mCount, dCount;
    cout << "How many minterms? ";
    cin >> mCount;
    cout << "Enter minterms: ";
    for (int i = 0; i < mCount; i++) {
        int m; cin >> m;
        minterms.push_back(m);
    }

    cout << "How many don't cares? ";
    cin >> dCount;
    cout << "Enter don't cares: ";
    for (int i = 0; i < dCount; i++) {
        int d; cin >> d;
        dontcares.push_back(d);
    }

    // Step 1: make initial list of terms
    vector<string> terms;
    for (int m : minterms) terms.push_back(toBinary(m, n));
    for (int d : dontcares) terms.push_back(toBinary(d, n));

    vector<string> primeImplicants;
    bool done = false;

    // Step 2: keep merging until no more merges possible
    while (!done) {
        vector<string> newTerms;
        vector<bool> used(terms.size(), false);

        for (int i = 0; i < terms.size(); i++) {
            for (int j = i + 1; j < terms.size(); j++) {
                string merged = merge(terms[i], terms[j]);
                if (merged != "") {
                    used[i] = true;
                    used[j] = true;
                    if (!contains(newTerms, merged))
                        newTerms.push_back(merged);
                }
            }
        }

        // add unused ones as prime implicants
        for (int i = 0; i < terms.size(); i++) {
            if (!used[i] && !contains(primeImplicants, terms[i]))
                primeImplicants.push_back(terms[i]);
        }

        if (newTerms.empty()) done = true;
        terms = newTerms;
    }

    // Step 3: output result (for simplicity, we’ll just print prime implicants)
    cout << "\nPrime Implicants:\n";
    for (string s : primeImplicants) {
        cout << toExpression(s) << endl;
    }

    // (Optional: build prime implicant chart and select essentials)
    // For beginner version, we stop here.

    return 0;
}
