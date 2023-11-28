#include <bits/stdc++.h>
using namespace std;

int maxCoins(vector<int>& piles) {
    int n = piles.size(), ans = 0;

    sort(piles.begin(), piles.end());
    for (int i : piles) {
        cout << i << " ";
    }
    cout << "\n";

    for (int i = 0, j = n-1; i < j; i++, j--) {
        ans += piles[j-1];
        j--;
    }

    return ans;
}

int main() {
    vector<int> piles = {9,8,7,6,5,1,2,3,4};

    cout << maxCoins(piles) << "\n";

    return 0;
}