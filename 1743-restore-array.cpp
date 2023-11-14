#include <bits/stdc++.h>
using namespace std;

/*
              {{4,-2},{1,4},{-3,1}} -> {-2,4,1,-3}
                 {{100000,-100000}} -> {100000,-100000}
                {{2,1},{3,4},{3,2}} -> {1,2,3,4}
    {{4,1},{7,9},{3,7},{5,4},{1,3}} -> {5,4,1,3,7,9}
*/

void printAdjacentPairs(vector<vector<int>>& adjacentPairs) {
    for (auto i : adjacentPairs) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}

// void dfs(unordered_map<int, vector<int>>& graph, int node, int prev_node, vector<int>& nums) {
//     nums.push_back(node);

//     if (graph[node].size() == 1) {
//         return;
//     }
       
//     if (graph[node][0] == prev_node) {
//         dfs(graph, graph[node][1], node, nums);
//     } else {
//         dfs(graph, graph[node][0], node, nums);
//     }
// }

void dfs(unordered_map<int, vector<int>>& graph, int node, int prev_node, vector<int>& nums) {
    nums.push_back(node);
    
    for (int neighbor : graph[node]) {
        if (neighbor != prev_node) {
            dfs(graph, neighbor, node, nums);
        }
    }
}

vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
    vector<int> nums;
    unordered_map<int, vector<int>> graph;

    for (auto edge : adjacentPairs) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    // for (auto i : graph) {
    //     cout << i.first << " -> ";
    //     for (auto j : i.second) {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    int root = 0;
    for (auto i : graph) {
        if (i.second.size() == 1) {
            root = i.first;
            break;
        }
    }

    nums.push_back(root);

    dfs(graph, graph[root][0], root, nums);

    return nums;
}

int main() {
    vector<vector<int>> adjacentPairs = {{4,1},{7,9},{3,7},{5,4},{1,3}};
    vector<int> nums = restoreArray(adjacentPairs);

    for (auto i : nums) {
        cout << i << " ";
    }
    
    return 0;
}