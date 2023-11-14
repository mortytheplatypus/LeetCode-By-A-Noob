#include <bits/stdc++.h>
using namespace std;

double myPow(double x, int n) {
    if (n == 0) {
        return 1;
    }
    
    if (n%2 == 0) {
        return myPow(x*x, n/2);
    } else if (n > 0) {
        return x*myPow(x*x, n/2);
    } else {
        return 1/x*myPow(x*x, n/2);
    }
}

int main() {
    double x;
    int n;
    cin >> x >> n;

    cout << myPow(x, n) << endl;
    
    return 0;
}