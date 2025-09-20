#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> minterms, dontcares;

struct Term {
    string bits;          // e.g. "10-1"
    set<int> cover;       // which minterms are covered
    bool used;
    Term(string b, set<int> c) {
        bits = b;
        cover = c;
        used = false;
    }
};

// Utility: convert number to binary string of length n
string toBinary(int num, int len) {
    string s = "";
    for (int i = len - 1; i >= 0; i--) {
        s += ((num >> i) & 1) ? '1' : '0';
    }
    return s;
}

// Try merging two terms, return merged bits or "" if not mergeable
string merge(string a, string b) {
    int diff = 0;
    string res = "";
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b[i]) res += a[i];
        else {
            res += '-';
            diff++;
        }
        if (diff > 1) return "";
    }
    return res;
}

// Check if list already has a term with same bits
bool contains(vector<Term> &list, Term &t) {
    for (auto &x : list) {
        if (x.bits == t.bits) return true;
    }
    return false;
}

// Convert bits to SOP expression
string bitsToExpr(string bits) {
    string term = "";
    char var = 'A';
    for (int i = 0; i < bits.size(); i++) {
        if (bits[i] == '1') term += var;
        else if (bits[i] == '0') term += var, term += '\'';
        var++;
    }
    if (term == "") return "1"; // covers all
    return term;
}

// Generate prime implicants
vector<Term> generatePrimeImplicants() {
    vector<Term> terms;
    for (int m : minterms) {
        terms.push_back(Term(toBinary(m, n), {m}));
    }
    for (int d : dontcares) {
        terms.push_back(Term(toBinary(d, n), {d}));
    }

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
                    terms[i].used = true;
                    terms[j].used = true;

                    set<int> uni = terms[i].cover;
                    uni.insert(terms[j].cover.begin(), terms[j].cover.end());

                    Term t(merged, uni);
                    if (!contains(newTerms, t)) newTerms.push_back(t);
                }
            }
        }

        for (auto &t : terms) {
            if (!t.used && !contains(primes, t)) primes.push_back(t);
        }

        terms = newTerms;

    } while (combined);

    for (auto &t : terms) {
        if (!contains(primes, t)) primes.push_back(t);
    }

    return primes;
}

// Find essential prime implicants
vector<Term> findEssentialPrimeImplicants(vector<Term> &primes) {
    vector<Term> essentials;

    for (int m : minterms) {
        vector<Term*> covers;
        for (auto &t : primes) {
            if (t.cover.count(m)) covers.push_back(&t);
        }
        if (covers.size() == 1) {
            Term *only = covers[0];
            bool already = false;
            for (auto &e : essentials) if (e.bits == only->bits) already = true;
            if (!already) essentials.push_back(*only);
        }
    }
    return essentials;
}

int main() {
    cout << "How many Variables (2<=n<=6)? --> ";
    cin >> n;

    int mCount, dCount;
    cout << "\nHow many Minterms? : ";
    cin >> mCount;
    cout << "Enter Minterms (space separated):\n";
    for (int i = 0; i < mCount; i++) {
        int m; cin >> m; minterms.push_back(m);
    }

    cout << "\nHow many Don't-Cares? : ";
    cin >> dCount;
    if (dCount > 0) {
        cout << "Enter Don't-Cares (space separated):\n";
        for (int i = 0; i < dCount; i++) {
            int d; cin >> d; dontcares.push_back(d);
        }
    }

    // Run QM
    vector<Term> primes = generatePrimeImplicants();
    vector<Term> essentials = findEssentialPrimeImplicants(primes);

    cout << "\nSimplified SOP Expression:\n";
    for (int i = 0; i < essentials.size(); i++) {
        cout << bitsToExpr(essentials[i].bits);
        if (i != essentials.size() - 1) cout << " + ";
    }
    cout << endl;
}
