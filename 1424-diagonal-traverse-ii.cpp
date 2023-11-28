#include <bits/stdc++.h>
using namespace std;

/*
    {{1,2,3,4,5},{6,7},{8},{9,10,11},{12,13,14,15,16}}
    {{1,2,3,4},{5,6,7,8,9,10},{11}}
*/

vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
    unordered_map<int, vector<int>> diagonalMap;
    int n = nums.size(), limit = n-1;

    for (int i = 0; i < n; i++) {
        int m = nums[i].size();
        limit = max(limit, n + m - 2);
        for (int j = 0; j < m; j++) {
            diagonalMap[i + j].push_back(nums[i][j]);
        }
    }

    vector<int> diagonalOrder;

    for (int i = 0; i <= limit; i++) {
        auto it = diagonalMap.find(i);

        if (diagonalMap.find(i) != diagonalMap.end()) {
            vector<int> diagonal = it->second;
            int m = diagonal.size();
            for (int j = m - 1; j >= 0; j--) {
                diagonalOrder.push_back(diagonal[j]);
            }
        }
    }
    
    return diagonalOrder;
}

int main() {
    vector<vector<int>> nums = {{1,2,3,4,5},{6,7},{8},{9,10,11},{12,13,14,15,16}}; 

    vector<int> diagonalOrder = findDiagonalOrder(nums);

    for (int i : diagonalOrder) {
        cout << i << " ";
    }

    return 0;
}