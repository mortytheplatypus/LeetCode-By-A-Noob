#include <bits/stdc++.h>
using namespace std;

int minTimeToVisitAllPoints(vector<vector<int>>& points) {
    int ans = 0, n = points.size();
    
    for (int i = 1; i < n; i++) {
        int x = abs(points[i][0] - points[i-1][0]);
        int y = abs(points[i][1] - points[i-1][1]);
        ans += max(x, y);
    }
    
    return ans;
}

int main() {
    vector<vector<int>> points = {{1,1},{3,4},{-1,0}};

    cout << minTimeToVisitAllPoints(points) << "\n";

    return 0;
}
       
