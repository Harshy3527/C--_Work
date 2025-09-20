#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> minterms, dontcares;
vector<int> table;

void getData();
void makeTable();
void printTable();
int binaryToGray(int num);
bool isValidGroup(int r, int c, int height, int width, vector<vector<int>> &KMaps, vector<vector<bool>> &visited);
void markGroupVisited(int r, int c, int height, int width, vector<vector<bool>> &visited);
string generateSOPTerm(int r, int c, int height, int width, int rowBits, int colBits, vector<vector<int>> &KMaps);
void mappingElements();

int main() {
    getData();
    makeTable();
    cout << "\nTruth Table:\n";
    printTable();
    mappingElements();
    return 0;
}

void getData() {
    int mintermNum, dontCareNum;
    cout << "How many Variables (2<=n<=6)? --> ";
    cin >> n;

    cout << "\nHow many Minterms & Don't-Cares? : ";
    cin >> mintermNum >> dontCareNum;

    cout << "\nEnter the Minterms:" << endl;
    for (int i = 0; i < mintermNum; i++) {
        int m;
        cin >> m;
        minterms.push_back(m);
    }

    cout << "Enter the Don't-Cares:" << endl;
    for (int i = 0; i < dontCareNum; i++) {
        int d;
        cin >> d;
        dontcares.push_back(d);
    }
}

void makeTable() {
    table.assign(1 << n, 0); // 2^n entries are 0

    for (int m : minterms)
        table[m] = 1;

    for (int d : dontcares)
        table[d] = -1; // -1 = don't-care
}

void printTable() {
    int rowBits = n / 2;
    int colBits = (n + 1) / 2;
    int rows = 1 << rowBits; 
    int cols = 1 << colBits; 

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            int index = (r << colBits) | c;
            if (table[index] == 1)
                cout << " 1";
            else if (table[index] == -1)
                cout << " X";
            else
                cout << " 0";
        }
        cout << endl;
    }
}



int binaryToGray(int num) {
    return num ^ (num >> 1);
}

bool isValidGroup(int r, int c, int height, int width, vector<vector<int>> &KMaps, vector<vector<bool>> &visited) {
    int rows = KMaps.size();
    int cols = KMaps[0].size();

    for (int dr = 0; dr < height; dr++) {
        for (int dc = 0; dc < width; dc++) {
            int newRow = (r + dr) % rows;
            int newCol = (c + dc) % cols;
            if (KMaps[newRow][newCol] == 0 || visited[newRow][newCol])
                return false;
        }
    }
    return true;
}

void markGroupVisited(int r, int c, int height, int width, vector<vector<bool>> &visited) {
    int rows = visited.size();
    int cols = visited[0].size();

    for (int dr = 0; dr < height; dr++) {
        for (int dc = 0; dc < width; dc++) {
            int newRow = (r + dr) % rows;
            int newCol = (c + dc) % cols;
            visited[newRow][newCol] = true;
        }
    }
}

string generateSOPTerm(int r, int c, int height, int width, int rowBits, int colBits, vector<vector<int>> &KMaps) {
    int rows = 1 << rowBits;
    int cols = 1 << colBits;
    vector<int> varValues(n, -1);

    for (int dr = 0; dr < height; dr++) {
        for (int dc = 0; dc < width; dc++) {
            int newRow = (r + dr) % rows;
            int newCol = (c + dc) % cols;
            int cellNum = (newRow << colBits) | newCol; // binary row+col

            for (int i = 0; i < n; i++) {
                int bit = (cellNum >> (n - i - 1)) & 1;
                if (varValues[i] == -1)
                    varValues[i] = bit;
                else if (varValues[i] != bit)
                    varValues[i] = -2; // varies
            }
        }
    }

    string term = "";
    char varName = 'A';
    for (int i = 0; i < n; i++) {
        if (varValues[i] == 0) {
            term += varName;
            term += '\'';
        } else if (varValues[i] == 1)
            term += varName;
        varName++;
    }
    if (term.empty())
        term = "1"; // covers whole K-map
    return term;
}

void mappingElements() {
    int rowBits = n / 2;
    int colBits = (n + 1) / 2; //like ceil but better 
    int rows = 1 << rowBits;
    int cols = 1 << colBits;

    vector<vector<int>> KMaps(rows, vector<int>(cols, 0));

    // Filling K-map using Gray code
    for (int i = 0; i < (1 << n); i++) {
        if (table[i] != 0) {
            int rowPart = i >> colBits; //MSB is row
            int colPart = i & ((1 << colBits) - 1); //LSB is col
            int row = binaryToGray(rowPart); //getting gray code
            int col = binaryToGray(colPart);
            KMaps[row][col] = table[i];
        }
    }

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    vector<string> SOPterms;

    // Start with largest groups first (powers of 2)
    for (int height = rows; height >= 1; height /= 2) {
        for (int width = cols; width >= 1; width /= 2) {
            for (int r = 0; r < rows; r++) {
                for (int c = 0; c < cols; c++) {
                    if (isValidGroup(r, c, height, width, KMaps, visited)) {
                        markGroupVisited(r, c, height, width, visited);
                        SOPterms.push_back(generateSOPTerm(r, c, height, width, rowBits, colBits, KMaps));
                    }
                }
            }
        }
    }

    cout << "\nSimplified SOP Expression:\n";
    for (size_t i = 0; i < SOPterms.size(); i++) {
        cout << SOPterms[i];
        if (i != SOPterms.size() - 1)
            cout << " + ";
    }
    cout << endl;
}
