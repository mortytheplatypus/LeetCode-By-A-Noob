#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    unordered_map<int, int> freq;

    for (int i=0; i<n; i++) {
        freq[nums[i]]++;
    }

    vector<int> res;
    priority_queue<pair<int, int>> pq;

    for (auto it: freq) {
        pq.push({it.second, it.first});
    }

    for (int i=0; i<k; i++) {
        res.push_back(pq.top().second);
        pq.pop();
    }

    return res;
}

int main() {
    vector<int> nums = {1,1,1,2,2,3};

    vector<int> res = topKFrequent(nums, 2);

    for (int i=0; i<res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}

  
