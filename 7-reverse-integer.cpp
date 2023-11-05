#include <bits/stdc++.h>
using namespace std;

int reverse(int x) {
    if (x == -2147483648) {
        return 0;
    }

    char limit_str[11] = "2147483647";

    bool isNegative = x < 0;
    if (isNegative) {
        x = -x;
    }

    char x_str[11];
    int len = 0;
    while (x) {
        x_str[len++] = x % 10 + '0';
        x /= 10;
    }
    x_str[len++] = '\0';

    // cout << x_str << "\n";
    // cout << "len: " << len << "\n";

    if (len == 11) {
        for (int i=0; i<10; i++) {
            if (x_str[i] > limit_str[i]) {
                return 0;
            } else if (x_str[i] < limit_str[i]) {
                break;
            }
        }
    }

    int n = 0;

    for (int i=0; x_str[i] != '\0'; i++) {
        n = n * 10 + (x_str[i] - '0');
    }

    if (isNegative) {
        n = -n;
    }

    return n;
}

int main() {
    int x; cin >> x;
    cout << reverse(x) << "\n";
    
    return 0;
}