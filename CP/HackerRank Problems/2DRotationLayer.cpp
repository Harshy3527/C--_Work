#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

void matrixRotation(vector<vector<int>> matrix, int r) {
    int m = matrix.size(), n = matrix[0].size(); int layers = min(m,n)/2;
    for (int L = 0; L < layers; L++) {
        vector<int> ring;
        int top = L, left = L, bottom = m - L - 1, right = n - L - 1;
        for (int j = left; j <= right; j++) ring.push_back(matrix[top][j]); 
        for (int i = top + 1; i <= bottom - 1; i++) ring.push_back(matrix[i][right]);
        for (int j = right; j >= left; j--) ring.push_back(matrix[bottom][j]);
        for (int i = bottom - 1; i >= top + 1; i--) ring.push_back(matrix[i][left]);

        int len = ring.size();
        int shift = r % len;
        rotate(ring.begin(), ring.begin() + shift, ring.end());
        int idx = 0; 
        for (int j = left; j <= right; j++) matrix[top][j] = ring[idx++];
        for (int i = top + 1; i <= bottom - 1; i++) matrix[i][right] = ring[idx++];
        for (int j = right; j >= left; j--) matrix[bottom][j] = ring[idx++];
        for (int i = bottom - 1; i >= top + 1; i--) matrix[i][left] = ring[idx++];
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }
}

int main()
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int m = stoi(first_multiple_input[0]);

    int n = stoi(first_multiple_input[1]);

    int r = stoi(first_multiple_input[2]);

    vector<vector<int>> matrix(m);

    for (int i = 0; i < m; i++) {
        matrix[i].resize(n);

        string matrix_row_temp_temp;
        getline(cin, matrix_row_temp_temp);

        vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }

    matrixRotation(matrix, r);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
