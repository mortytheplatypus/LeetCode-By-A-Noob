#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;

int countHomogenous(string s) {
    int n = s.size();
    unsigned long long ans = 0, count = 1;

    for (int i=1; i<n; i++) {
        if (s[i] != s[i-1]) {
            ans += (count * (count + 1)) / 2;
            ans %= MOD;
            count = 0;
        }
        count++;
    }

    ans += (count * (count + 1)) / 2;
    ans %= MOD;

    return ans;
}

int main() {
    string s = "abbcccaa";
    cout << countHomogenous(s) << endl;
    
    return 0;
}