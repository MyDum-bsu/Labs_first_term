#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int GetElementOfMatrix(const vector<vector<int>> &matrix, int i, int j) {
    if ((i + j) < matrix.size())
        return matrix[i][j];
    return matrix[-j + matrix.size() - 1][-i + matrix.size() - 1];
}
void cinMatrix(vector<vector<int>> &matrix, int &n) {

    for (int i = n - 1, k = 0; i >= 0; i--, k++) {
        for (int j = 0; j <= i; ++j) {
            int val;
            cout << "Enter " << j << " element of " << n - i - 1 << " string" << endl;
            cin >> val;
            matrix[k].push_back(val);
        }
    }

}
void coutMatrix(vector<vector<int>> &matrix, int &n) {
    cout << "You have entered a matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << " | ";
        for (int j = 0; j < matrix.size(); ++j) {
            cout << GetElementOfMatrix(matrix, i, j) << " | ";
        }
        cout << endl;

    }

}

bool isLocalMinimum(vector<vector<int>> &matrix, int i, int j) {
    int el = GetElementOfMatrix(matrix, i, j);
    for (int k = -1; k <= 1; ++k) {
        for (int l = -1; l <= 1; ++l) {
//      if ((X + Xi >= 0) && (X + Xi < matrix.size()) && (Y + Yi >= 0) && (Y + Yi < matrix.size()))
//        if ((GetElementOfMatrix(matrix, X, Y) >= GetElementOfMatrix(matrix, X + Xi, Y + Yi)) && (X != 0) && (Y != 0))
//          return false;
//  return true;
            if ((i + k >= 0) && (j + l >= 0)
                && (i + k < matrix.size()) && (j + l < matrix.size()) && ((k != 0) || (l != 0))) {
                if (GetElementOfMatrix(matrix, i + k, j + l) <= el) {
                    return false;
                }
            }
        }
    }
    return true;
}

void numberofLocalMinimums(vector<vector<int>> &matrix) {
    int numberOfMin = 0;
    cout << "Number of local minimums: ";
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix.size(); ++j) {
            if (isLocalMinimum(matrix, i, j)) {
                numberOfMin += 1;
            }

        }
    }
    cout << numberOfMin << endl;
}
void SumOftheElementsAbovetheMainDiagonal(vector<vector<int>> &matrix, int n) {
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            sum += abs(GetElementOfMatrix(matrix, i, j));
        }
    }
    cout << "The sum of the modules of the elements above the main diagonal of the matrix: " << sum;
}
int main() {
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>());
    cinMatrix(matrix, n);
    coutMatrix(matrix, n);
    numberofLocalMinimums(matrix);
    SumOftheElementsAbovetheMainDiagonal(matrix, n);
    return 0;
}