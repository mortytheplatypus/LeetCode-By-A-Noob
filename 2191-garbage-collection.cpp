#include <bits/stdc++.h>
using namespace std;

int garbageCollection(vector<string>& garbage, vector<int>& travel) {
    int ans = 0, n = garbage.size();

    int lastG = -1, lastP = -1, lastM = -1;
    int flag = 3;

    for (int i = n-1; i>=0; i--) {
        ans += garbage[i].size();

        if (flag > 0) {
            for (char c : garbage[i]) {
                if (c == 'G') {
                    if (lastG == -1) {
                        lastG = i;
                        flag--;
                    }
                } else if (c == 'P') {
                    if (lastP == -1) {
                        lastP = i;
                        flag--;
                    }
                } else if (c == 'M') {
                    if (lastM == -1) {
                        lastM = i;
                        flag--;
                    }
                }
            }
        }
    }

    cout << ans << "\n";

    int minimum = min(lastG, min(lastP, lastM));
    int middle = lastG + lastP + lastM - minimum - (n-1);

    cout << minimum << " " << middle << " " << n-1 << "\n";

    if (middle == -1) {
        // one type of garbage
        for (int num : travel) {
            ans += num;
        }
    } else if (minimum == -1) {
        // two types of garbage
        for (int i=0; i<middle; i++) {
            ans += travel[i];
            ans += travel[i];
        }

        for (int i=middle; i<n-1; i++) {
            ans += travel[i];
        }
    } else {
        // three types of garbage
        for (int i=0; i<minimum; i++) {
            ans += travel[i];
            ans += travel[i];
            ans += travel[i];
        }

        for (int i=minimum; i<middle; i++) {
            ans += travel[i];
            ans += travel[i];
        }

        for (int i=middle; i<n-1; i++) {
            ans += travel[i];
        }
    }

    return ans;
}

int main() {
    vector<string> garbage = {"G","M","P"};
    vector<int> travel = {1,3};

    cout << garbageCollection(garbage, travel) << "\n";

    return 0;
}