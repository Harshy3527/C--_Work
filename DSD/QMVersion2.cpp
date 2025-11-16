#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> minterms, dontCares;

struct Term {
    string bits;      
    vector<int> covered; 
    bool used;        
    Term(string b, vector<int> c) {
        bits = b;
        covered = c;
        used = false;
    }
};

// Number to binary string
string toBinary(int num, int len) {
    string s = "";
    for (int i = len - 1; i >= 0; i--) {
        s += ((num >> i) & 1) ? '1' : '0';
    }
    return s;
}

// Merge two terms
string merge(string a, string b) {
    int diff = 0;
    string result = "";
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b[i]) result += a[i];
        else {
            result += '-';
            diff++;
        }
        if (diff > 1) return "";
    }
    return result;
}

// Check if term already exists
bool contains(vector<Term> &allTerms, Term &t) {
    for (auto &x : allTerms) if (x.bits == t.bits) return true;
    return false;
}

// Bits to SOP
string bitsToExpr(string bits) {
    string term = "";
    char var = 'A';
    for (char c : bits) {
        if (c == '1') term += var;
        else if (c == '0') { term += var; term += '\''; }
        var++;
    }
    if (term == "") return "1";
    return term;
}

// Generate prime implicants
vector<Term> generatePrimeImplicants() {
    vector<Term> terms;
    for (int m : minterms) terms.push_back(Term(toBinary(m, n), {m}));
    for (int d : dontCares) terms.push_back(Term(toBinary(d, n), {d}));

    vector<Term> primes;
    bool combined;
    do {
        combined = false;
        vector<Term> newTerms;

        for (int i = 0; i < terms.size(); i++) {
            for (int j = i + 1; j < terms.size(); j++) {
                string merged = merge(terms[i].bits, terms[j].bits);
                if (merged != "") {
                    combined = true;
                    terms[i].used = terms[j].used = true;
                    vector<int> allCovered = terms[i].covered;
                    allCovered.insert(allCovered.end(), terms[j].covered.begin(), terms[j].covered.end());
                    Term t(merged, allCovered);
                    if (!contains(newTerms, t)) newTerms.push_back(t);
                }
            }
        }

        for (auto &t : terms) if (!t.used && !contains(primes, t)) primes.push_back(t);
        terms = newTerms;

    } while (combined);

    for (auto &t : terms) if (!contains(primes, t)) primes.push_back(t);
    return primes;
}

// Find essential prime implicants
vector<Term> findEssentialPrimeImplicants(vector<Term> &primes) {
    vector<Term> essentials;
    for (int m : minterms) {
        vector<Term> covers;
        for (auto &t : primes) if (find(t.covered.begin(), t.covered.end(), m) != t.covered.end()) covers.push_back(t);
        if (covers.size() == 1) {
            bool exists = false;
            for (auto &e : essentials) if (e.bits == covers[0].bits) exists = true;
            if (!exists) essentials.push_back(covers[0]);
        }
    }
    return essentials;
}

// Petrick's Method (vector-based)
vector<vector<int>> petrickMethod(vector<Term> &primes, vector<Term> &essentials) {
    vector<int> coveredMinterms;
    for (auto &t : essentials) coveredMinterms.insert(coveredMinterms.end(), t.covered.begin(), t.covered.end());

    vector<int> remaining;
    for (int m : minterms)
        if (find(coveredMinterms.begin(), coveredMinterms.end(), m) == coveredMinterms.end())
            remaining.push_back(m);
    if (remaining.empty()) return {};

    // Options for each uncovered minterm
    vector<vector<int>> options;
    for (int m : remaining) {
        vector<int> temp;
        for (int i = 0; i < primes.size(); i++)
            if (find(primes[i].covered.begin(), primes[i].covered.end(), m) != primes[i].covered.end())
                temp.push_back(i);
        options.push_back(temp);
    }

    // Multiply sums
    vector<vector<int>> prod = {{}};
    for (auto &opt : options) {
        vector<vector<int>> newProd;
        for (auto &p : prod) {
            for (int idx : opt) {
                vector<int> temp = p;
                temp.push_back(idx);
                newProd.push_back(temp);
            }
        }
        prod = newProd;
    }

    // Remove duplicates in each product
    for (auto &p : prod) {
        sort(p.begin(), p.end());
        p.erase(unique(p.begin(), p.end()), p.end());
    }

    // Find minimal products
    int minSize = INT_MAX;
    for (auto &p : prod) minSize = min(minSize, (int)p.size());

    vector<vector<int>> minimal;
    for (auto &p : prod) if (p.size() == minSize) minimal.push_back(p);

    return minimal;
}

int main() {
    int input = 1;
    while (input != 0) {
        minterms.clear(); dontCares.clear();

        cout << "How many Variables (2<=n<=6)? --> ";
        cin >> n;

        int mCount, dCount;
        cout << "\nHow many Minterms? : "; cin >> mCount;
        cout << "Enter Minterms (space separated):\n";
        for (int i = 0; i < mCount; i++) { int m; cin >> m; minterms.push_back(m); }

        cout << "\nHow many Don't-Cares? : "; cin >> dCount;
        if (dCount > 0) {
            cout << "Enter Don't-Cares (space separated):\n";
            for (int i = 0; i < dCount; i++) { int d; cin >> d; dontCares.push_back(d); }
        }

        vector<Term> primes = generatePrimeImplicants();
        vector<Term> essentials = findEssentialPrimeImplicants(primes);
        vector<vector<int>> minimalPetrick = petrickMethod(primes, essentials);

        cout << "\nSimplified SOP Expression:\n";

        // Combine essentials + first minimal Petrick combination
        vector<string> finalBits;
        for (auto &t : essentials) finalBits.push_back(t.bits);
        if (!minimalPetrick.empty())
            for (int idx : minimalPetrick[0]) finalBits.push_back(primes[idx].bits);

        for (int i = 0; i < finalBits.size(); i++) {
            cout << bitsToExpr(finalBits[i]);
            if (i != finalBits.size() - 1) cout << " + ";
        }
        cout << endl;

        cout << "Press 0 to exit or any other number to run again: ";
        cin >> input;
    }
}
