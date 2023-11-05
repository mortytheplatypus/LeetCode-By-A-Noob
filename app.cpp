#include <bits/stdc++.h>
using namespace std;

int getWinner(vector<int>& arr, int k) {
    int n = arr.size();

    int count = 0, winner = arr[0], max = arr[0];
    for (int i=1; i<n && count < k; i++) {
        // if the current element is greater than the previous element, we swap the winner
        if (arr[i] > winner) {
            winner = arr[i];
            count = 1;
        } else {
            count++;
        }
    }

    return winner;
}

int main() {
    vector<int> arr = {2, 1, 3, 5, 4, 6, 7};
    int k = 2;

    cout << getWinner(arr, k) << "\n";
    
    return 0;
}