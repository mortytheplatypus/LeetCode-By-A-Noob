#include <bits/stdc++.h>
using namespace std;

vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    int n = nums.size(), totalSum = 0, currentSum = 0;
    vector<int> result(n);

    for (int i = 0; i < n; i++) {
        totalSum += nums[i];
    }

    for (int i=0; i<n; i++) {
        result[i] = (nums[i] * i) - currentSum + (totalSum - currentSum) - (nums[i] * (n - i));
        currentSum += nums[i];
    }

    return result;
}

int main() {
    vector<int> nums = {1,4,6,8,10};
    vector<int> result = getSumAbsoluteDifferences(nums);

    for (int i=0; i<result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}