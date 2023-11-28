#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;

int numberOfWays(string corridor) {
    int n = corridor.size();
    vector<int> seatPositions;

    for (int i = 0; i < n; i++) {
        if (corridor[i] == 'S') {
            seatPositions.push_back(i);
        }
    }

    int m = seatPositions.size();

    if (m % 2 == 1 || m < 2) {
        return 0;
    }

    unsigned long long ans = 1;

    m--;
    for (int i = 1; i < m; i += 2) {
        ans = (ans%MOD) * (seatPositions[i + 1] - seatPositions[i]);
        ans = ans%MOD;
    }

    return ans%MOD;
}

int main() {
    string corridor = "SSPPSPS"; 

    cout << numberOfWays(corridor) << "\n";

    return 0;
}