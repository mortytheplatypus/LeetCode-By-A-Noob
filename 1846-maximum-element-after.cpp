#include <bits/stdc++.h>
using namespace std;

/*
    case 1: 2 2 2 2 2 -> 1 2 2 2 2
    case 2: 7 7 7 7 7 -> 1 2 3 4 5
    case 3: 2 2 2 7 7 -> 1 2 2 3 4
    case 4: 1 8 8 8 8 -> 1 2 3 4 5
    case 5: 1 2 7 7 7 -> 1 2 3 4 5
*/

int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int n = arr.size(), max = 1;
    arr[0] = 1;

    for (int i=1; i<n && max <= n; i++) {
        if (arr[i] - arr[i-1] > 1) {
            arr[i] = arr[i-1] + 1;
        }
        max = arr[i];
    }

    return max;
}

int main() {
    vector<int> arr = {1,2,3,4,5};
    cout << maximumElementAfterDecrementingAndRearranging(arr) << endl;
    
    return 0;
}