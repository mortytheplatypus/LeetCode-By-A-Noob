#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector< vector<string> > groups;
    map< string, vector<string> > mp;
    int len = strs.size();

    for (string str : strs) {
        string s = str;
        sort(s.begin(), s.end());
        mp[s].push_back(str);
    }

    for (auto i : mp) {
        groups.push_back(i.second);
    }

    return groups;
}

int main() {
    return 0;
}