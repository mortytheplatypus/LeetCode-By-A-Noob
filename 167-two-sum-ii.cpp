#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int n = numbers.size();

    int i=0, j=n-1;
    while (i < j) {
        int sum = numbers[i] + numbers[j];
        if (sum == target) {
            return {i+1, j+1};
        } else if (sum < target) {
            i++;
        } else {
            j--;
        }
    }

    return {-1, -1};
}


int main() {
    vector<int> numbers = {2,7,11,15};
    int target = 9;
    
    return 0;
}