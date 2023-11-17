#include <bits/stdc++.h>
using namespace std;

int minPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int n = nums.size();
    int max = nums[0] + nums[n-1];

    for (int i=1, j=n-2; i<j; i++, j--) {
        if (nums[i] + nums[j] > max) {
            max = nums[i] + nums[j];
        }
    }

    return max;
}

int main() {
    //
    
    return 0;
}