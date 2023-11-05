#include <bits/stdc++.h>
using namespace std;

// use unordered_map instead of map for better performance
// unordered_map -> Red-Black Tree
// map -> Hash Table

vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> mp;
    int n = nums.size();
    for (int i=0; i<n; i++) {
        if (mp.find(target-nums[i]) != mp.end()) {
            return {mp[target-nums[i]], i};
        }
        mp[nums[i]] = i;
    }

    // since one solution surely exists within the input array, no need for further check

    return {-1, -1};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> ans = twoSum(nums, target);
    for (int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}