#include <bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int n = digits.size(), carry = 1;

    if (digits.back() < 9) {
        digits.back()++;
        return digits;
    }

    for (int i = n-1; i>=0 && carry==1; i--) {
        digits[i] += carry;
        carry = digits[i] / 10;
        digits[i] %= 10;
    }
    
    if (carry) {
        digits.insert(digits.begin(), carry);
    }

    return digits;        
}

int main() {
    vector<int> digits = {9};
    
    vector<int> ans = plusOne(digits);
    for (int i : ans) {
        cout << i << " ";
    }
    
    return 0;
}