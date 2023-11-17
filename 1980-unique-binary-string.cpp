#include <bits/stdc++.h>
using namespace std;

/*
    {"111","011","001"}
    {"1010","1111","0000","1101"}
*/

string findDifferentBinaryString(vector<string>& nums) {
    int n = nums.size();
    unordered_set<string> s;

    for (string num : nums) {
        s.insert(num);
    }

    string num = "";
    for (int i=0; i<n; i++) {
        num += "0";
    }

    int i = n-1;
    bool flag = true;

    while (s.find(num) != s.end() && i >= 0) {
        if (flag) {
            num[i] = '1';
            flag = false;
        } else {
            num[i] = '0';
            flag = true;
            i--;
        }        
    }

    return num;
}

int main() {
    vector<string> nums = {"1010","1111","0000","1101"};
    cout << findDifferentBinaryString(nums) << endl;
    
    return 0;
}