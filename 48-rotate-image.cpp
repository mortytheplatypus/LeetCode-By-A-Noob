#include <bits/stdc++.h>
using namespace std;

void printMatrix(vector<vector<int>>& matrix) {
    int n = matrix.size();
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

/*
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = n/2;
    
    cout << "Before: \n";
    printMatrix(matrix);
    cout << "\n";

    // transpose
    for (int i=0; i<n; i++) {
        for (int j=0; j<i; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // mirror
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            swap(matrix[i][j], matrix[i][n-j-1]);
        }
    }

    cout << "After: \n";
    printMatrix(matrix);
    cout << "\n\n";
} 
*/

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = n/2;

    // transpose and swap
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
        reverse(matrix[i].begin(),matrix[i].end());
    }
}

int main() {
    vector<vector<int>> matrix1 = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> matrix2 = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};

    rotate(matrix1);
    rotate(matrix2);
    
    return 0;
}