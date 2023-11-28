#include <bits/stdc++.h>
using namespace std;

int reductionOperations(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size(), min = nums[0], count = 0, distinctCount = 0;

    int secondMinIndex = 1;
    for (int i=1; i<n && nums[i] == min; i++, secondMinIndex++);

    for (int i=secondMinIndex; i<n; i++) {
        if (nums[i] != nums[i-1]) {
            distinctCount++;
        }

        count += distinctCount;
    }
    
    return count;
}

int main() {
    vector<int> nums = {1,1,2,2,3};
    int k = 6;

    cout << reductionOperations(nums) << "\n";

    return 0;
}