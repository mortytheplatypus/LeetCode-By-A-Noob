#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;

int reverse(int n) {
    int rev=0;

    while (n) {
        rev = rev*10 + n%10;
        n /= 10;
    }

    return rev;
}

int countNicePairs(vector<int>& nums) {
    int nicePairs = 0;

    unordered_map<int, int> freq;

    for (int num : nums) {
        int rev = reverse(num);
        nicePairs = (nicePairs + freq[num - rev]) % MOD;
        freq[num - rev]++;
    }

    return nicePairs;
}

int main() {
    vector<int> nums = {13,10,11,35,1,55,124,24,76}; 
    
    cout << countNicePairs(nums) << "\n";

    return 0;
}

/*
Animation: 13,10,11,35,1,55,124,24,76

    freq = {}
    nicePairs = 0
    13 -> 31 -> 13-31 = -18 -> freq[-18] = 0 -> nicePairs = 0+0 = 0
    freq[-18] = 1

    10 -> 01 -> 10-01 = 9 -> freq[9] = 0 -> nicePairs = 0+0 = 0
    freq[9] = 1

    11 -> 11 -> 11-11 = 0 -> freq[0] = 0 -> nicePairs = 0+0 = 0
    freq[0] = 1

    35 -> 53 -> 35-53 = -18 -> freq[-18] = 1 -> nicePairs = 0+1 = 1
    freq[-18] = 2

    1 -> 1 -> 1-1 = 0 -> freq[0] = 1 -> nicePairs = 1+1 = 2
    freq[0] = 2

    55 -> 55 -> 55-55 = 0 -> freq[0] = 2 -> nicePairs = 2+2 = 4
    freq[0] = 3

    124 -> 421 -> 124-421 = -297 -> freq[-297] = 0 -> nicePairs = 4+0 = 4
    freq[-297] = 1

    24 -> 42 -> 24-42 = -18 -> freq[-18] = 2 -> nicePairs = 4+2 = 6
    freq[-18] = 3

    76 -> 67 -> 76-67 = 9 -> freq[9] = 1 -> nicePairs = 6+1 = 7
    freq[9] = 2
*/
