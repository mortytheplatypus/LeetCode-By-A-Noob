#include <bits/stdc++.h>
using namespace std;

long long largestPerimeter(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    
    int n = nums.size();
    long long largest = -1, cumSum = nums[0] + nums[1];

    for (int i = 2; i < n; i++) {
        if (cumSum > nums[i]) {
            largest = cumSum + nums[i];
        }
        cumSum += nums[i];
    }

    return largest;
}

int main() {
    vector<int> nums = {1,12,1,2,5,50,3};

    cout << largestPerimeter(nums) << "\n";

    return 0;
}

