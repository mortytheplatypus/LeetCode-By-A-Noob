#include <bits/stdc++.h>
using namespace std;

bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
    int width = abs(sx - fx), height = abs(sy - fy);
    
    if (width == 0 && height == 0 && t == 1) {
        return false;
    }
    return t >= max(width, height);
}

int main() {
    int sx = 2, sy = 4, fx = 7, fy = 7, t = 6;
    if (isReachableAtTime(sx, sy, fx, fy, t)) {
        cout << "true";
    } else {
        cout << "false";
    }
    
    return 0;
}