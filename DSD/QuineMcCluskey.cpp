#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> minterms, dontCares;

struct Term {
    string bits;            // stuff like "10-1"
    set<int> covered;       // which minterms are covered
    bool used;              // flag as true after two terms gets merged once (output is false)
    Term(string b, set<int> c) {
        bits = b;
        covered = c;
        used = false;
    }
};

// Number to binary string
string toBinary(int num, int len) {
    string s = "";
    for (int i = len - 1; i >= 0; i--) {
        s += ((num >> i) & 1) ? '1' : '0';  //extracting bit at ith position and appending
    }
    return s;
}

string merge(string a, string b) {
    int diff = 0;
    string result = "";
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b[i]) 
            result += a[i];
        else {
            result += '-';
            diff++;
        }
        if (diff > 1)       //if more than 1 bit differ, don't merge 
            return "";
    }
    return result;
}

// Checking if allTerms already has a term with same bits
bool contains(vector<Term> allTerms, Term t) {  //checking if any object Term has a "bits" = t.bits
    for (int i = 0; i < allTerms.size(); i++) {
        if (allTerms[i].bits == t.bits) {
            return true;  
        }
    }
    return false; 
}


// Converting bits to SOP
string bitsToExpr(string bits) {
    string term = "";
    char var = 'A';
    for (int i = 0; i < bits.size(); i++) {
        if (bits[i] == '1') 
            term += var;
        else if (bits[i] == '0'){ 
            term += var;
            term += '\''; //A' gets appended 
        }
        var++;
    }
    if (term == "") 
        return "1"; // for edge case -> ____ 
    return term;
}

// Generate prime implicants
vector<Term> generatePrimeImplicants() {
    vector<Term> terms;
    for (int m : minterms) {
        terms.push_back(Term(toBinary(m, n), {m})); //convert every minterm to binary string and put it in Term object and mark it in covered = {m}
    }
    for (int d : dontCares) {
        terms.push_back(Term(toBinary(d, n), {d})); // same thing, just mark it as {d} now
    }

    vector<Term> primes; // final prime implicants are stored here
    bool combined;      // did any merging happen in this iteration?

    do {
        combined = false;
        vector<Term> newTerms;  // new terms after merging 

        for (int i = 0; i < terms.size(); i++) {
            for (int j = i + 1; j < terms.size(); j++) {
                string merged = merge(terms[i].bits, terms[j].bits);  // merge i-th term with terms below it 
                if (merged != "") {  //merging success
                    combined = true;
                    terms[i].used = true;
                    terms[j].used = true;

                    set<int> allMergedMinterms = terms[i].covered; //add all minterms covered by 1st one
                    allMergedMinterms.insert(terms[j].covered.begin(), terms[j].covered.end()); //

                    Term t(merged, allMergedMinterms); 
                    if (!contains(newTerms, t)) newTerms.push_back(t); //add new term to the newTerms if its not already there
                }
            }
        }

        for (auto &t : terms) {      //if a term couldn't be merged, it is a prime implicant also
            if (!t.used && !contains(primes, t)) 
                primes.push_back(t);
        }

        terms = newTerms;   //now merge the already merged terms 

    } while (combined); //keep running until no merging is possible 

    for (auto &t : terms) {
        if (!contains(primes, t)) primes.push_back(t);  //add leftover prime implicants to primes
    }

    return primes;
}

// Find essential prime implicants
vector<Term> findEssentialPrimeImplicants(vector<Term> primes) {
    vector<Term> essentials;

    for (int i = 0; i < minterms.size(); i++) {
        int m = minterms[i];
        vector<Term> covers;

        // Find all prime implicants that cover this minterm
        for (int j = 0; j < primes.size(); j++) {
            if (primes[j].covered.count(m)) {
                covers.push_back(primes[j]); // copy term into covers
            }
        }

        // If just 1 term covers this minterm -> essential
        if (covers.size() == 1) {
            Term only = covers[0];

            // Check if it's already in essentials
            bool alreadyExists = false;
            for (int k = 0; k < essentials.size(); k++) {
                if (essentials[k].bits == only.bits) {
                    alreadyExists = true;
                    break;
                }
            }

            // Add to essentials if not already present
            if (!alreadyExists) {
                essentials.push_back(only);
            }
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
            int d; cin >> d; dontCares.push_back(d);
        }
    }

    // Run QM
    vector<Term> primes = generatePrimeImplicants();
    vector<Term> essentials = findEssentialPrimeImplicants(primes);

    cout << "\nSimplified SOP Expression:\n";
    for (int i = 0; i < essentials.size(); i++) {
        cout << bitsToExpr(essentials[i].bits);
        if (i != essentials.size() - 1) 
            cout << " + ";
    }
    cout << endl;
}
