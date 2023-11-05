#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    vector<vector<int>> result;
    int n = nums.size();

    for (int i=0; i<n-2; i++) {
        if (nums[i] > 0) {
            break;
        }

        if (i>0 && nums[i]==nums[i-1]) {
            continue;
        }

        int low = i+1, high = n-1, sum;
        while (low < high) {
            sum = nums[i] + nums[low] + nums[high];

            if (sum > 0) {
                high--;
            } else if (sum < 0) {
                low++;
            } else {
                result.push_back({nums[i], nums[low], nums[high]});
                while (low < high && nums[low]==nums[low+1]) {
                    low++;
                }
                while (low < high && nums[high]==nums[high-1]) {
                    high--;
                }
                low++;
                high--;
            }
        }

    }

    return result;
}


int main() {
    vector<int> numbers = {-1,0,1,2,-1,-4};
    
    vector<vector<int>> result = threeSum(numbers);

    for (int i=0; i<result.size(); i++) {
        for (int j=0; j<result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}