#include <bits/stdc++.h>
using namespace std;

// using stl map consumes too much memory and runtime is also not fast
/*
bool containsDuplicate(vector<int>& nums) {
    map<int, int> mp;

    int n = nums.size();
    for (int i=0; i<n; i++) {
        if (mp.find(nums[i]) != mp.end()) {
            return true;
        }
        mp[nums[i]] = 1;
    }

    return false;
}
*/

// sorting and checking adjacent elements is faster than using map
bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int n = nums.size() - 1;
    for (int i=0; i<n; i++) {
        if (nums[i] == nums[i+1]) return true;
    }

    return false;
}

int main() {
    return 0;
}