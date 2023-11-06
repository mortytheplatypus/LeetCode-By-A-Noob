#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) {
    int n = height.size(), maxArea=0;

    int i = 0, j = n-1;
    while (i < j) {
        maxArea = max(maxArea, (j-i) * min(height[i], height[j]));
        if (height[i] < height[j]) {
            i++;
        } else {
            j--;
        }
    }

    return maxArea;
}

int main() {
    vector<int> arr = {2,3,10,5,7,8,9};
    
    cout << maxArea(arr) << "\n";
    
    return 0;
}