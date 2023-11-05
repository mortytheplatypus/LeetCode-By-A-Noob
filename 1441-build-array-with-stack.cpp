#include <bits/stdc++.h>
using namespace std;

/*
    input = [1, 2, 3]
    target = [1, 3]

    stream = [t, f, t]
*/

string push = "Push", pop = "Pop";
vector<string> buildArray(vector<int>& target, int n) {
    vector<string> output;
    int m = target.size();
    int current = 0;
    
    for (int i=0; i<m; i++) {
        output.push_back(push);
        if (target[i] != current+1) {
            output.push_back(pop);
            current++;
            i--;
        }
    }

    return output;
}


int main() {
    vector<int> target = {1, 3};
    int n = 3;

    vector<string> output = buildArray(target, n);
    for (int i=0; i<output.size(); i++) {
        cout << output[i] << " ";
    }
    
    return 0;
}