#include <bits/stdc++.h>
using namespace std;

/*
vector<int> v:
     0 := no ants
    +1 := ants in right direction
    -1 := ants in left direction
     2 := both ants 
*/

int getLastMoment(int n, vector<int>& left, vector<int>& right) {
    int l = left.size(), r = right.size();
    int ants = l+r;

    vector<int> v(n+1);
    for (auto i : left) {
        v[i] = -1;
    }

    for (auto i : right) {
        v[i] = +1;
    }

    while (ants) {
        if (v[0] = -1) {
            ants--;
        }
        if (v[n-1] == +1) {
            ants--;
        }
    }
}

int main() {
    //
    
    return 0;
}