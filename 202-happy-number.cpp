#include <bits/stdc++.h>
using namespace std;

int squares[10] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81};

bool isHappy(int n) {
    if (n < 4) return n==1;
    
    while (n > 3) {
        int m = 0;
        while (n) {
            m += squares[n%10];

            n /= 10;
        }
        n = m;
        cout << m << endl;
        if (m == 4) {
            return false;
        }
    }
    
    if (n == 1) return true;
    
    return false;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (isHappy(n)) printf("Happy\n");
        else printf("Unhappy\n");
    }
    
    return 0;
}