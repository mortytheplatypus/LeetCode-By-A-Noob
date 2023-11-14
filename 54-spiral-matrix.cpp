#include <bits/stdc++.h>
using namespace std;

/*
    {{1,2,3}, {4,5,6}, {7,8,9}} -> 1, 2, 3, 6, 9, 8, 7, 4, 5
    {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}} -> 1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7
*/

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<bool>> visited (m, vector<bool>(n, false));
    vector<int> spiral;

    bool row = true; // true := left to right, false := right to left
    bool col = true; // true := top to bottom, false := bottom to top

    /*
          row |  col  | movement
        --------------------
         true | true  | left to right
        false | true  | top to bottom
        false | false | right to left
         true | false | bottom to top
    */

    int count = m*n, i=0, j=0;

    while(count--) {
        spiral.push_back(matrix[i][j]);
        visited[i][j] = true;

        if (row & col) {
            j++;
            if (j == n || visited[i][j]) {
                j--;
                i++;
                row = false;
            }
        } else if (!row & col) {
            i++;
            if (i == m || visited[i][j]) {
                i--;
                j--;
                col = false;
            }
        } else if (!row & !col) {
            j--;
            if (j == -1 || visited[i][j]) {
                j++;
                i--;
                row = true;
            }
        } else if (row & !col) {
            i--;
            if (i == -1 || visited[i][j]) {
                i++;
                j++;
                col = true;
            }
        }
    }

    for (int i : spiral) {
        cout << i << " ";
    }
    cout << "\n";
    
    return spiral;
}

int main() {
    vector<vector<int>> matrix = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}}; 

    vector<int> spiral = spiralOrder(matrix);

    for (auto i : spiral) {
        cout << i << " ";
    }
    cout << "\n";
    
    return 0;
}