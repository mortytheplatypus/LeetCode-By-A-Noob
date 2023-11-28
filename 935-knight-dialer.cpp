#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;
int movesCount[10] = {2, 2, 2, 2, 3, 0, 3, 2, 2, 2};
vector<vector<int>> moves = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};

int knightDialer(int n) {
    unsigned long long count = 0;
    vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(10, 0));
    for (int i = 0; i < 10; i++) dp[1][i] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < movesCount[j]; k++) {
                dp[i][j] += dp[i - 1][moves[j][k]];
            }
            dp[i][j] %= MOD;
        }
    }
    for (int i = 0; i < 10; i++) count += dp[n][i];

    return count % MOD;
}

int main() {
    int n; cin >> n;
    cout << knightDialer(n) << "\n";

    return 0;
}