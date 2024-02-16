#include <bits/stdc++.h>
using namespace std;

int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
    unordered_map<int, int> freq;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    vector<int> freqArr;
    for (auto it = freq.begin(); it != freq.end(); it++) {
        freqArr.push_back(it->second);
    }

    sort(freqArr.begin(), freqArr.end());

    int i = 0;
    while (k > 0) {
        if (k >= freqArr[i]) {
            k -= freqArr[i];
            i++;
        } else {
            break;
        }
    }

    return freqArr.size() - i;
}

int main() {
    vector<int> arr = {4,3,1,1,3,3,2};
    int k = 3;

    cout << findLeastNumOfUniqueInts(arr, k) << "\n";

    return 0;
}



