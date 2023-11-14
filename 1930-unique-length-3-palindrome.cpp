#include <bits/stdc++.h>
using namespace std;

int countPalindromicSubsequence(string s) {
    int count = 0, n = s.length();

    vector<vector<int>> occurrences(26, vector<int>(2, -1));

    for (int i=0; i<n; i++) {
        int index = s[i] - 'a';
        if (occurrences[index][0] == -1) {
            occurrences[index][0] = i;
        }
        occurrences[index][1] = i;
    }

    for (int i=0; i<26; i++) {
        if (occurrences[i][1] != -1) {
            unordered_set<char> unique_between;
            for (int j=occurrences[i][0]+1; j<occurrences[i][1]; j++) {
                unique_between.insert(s[j]);
            }
            count += unique_between.size();
        }
    }
    
    return count;
}

int main() {
    string s = "bbcdbccabaa";
    /*
        bcb bdb bbb bab
        cdc cbc ccc
        aba aaa
    */
    
    cout << countPalindromicSubsequence(s) << "\n";
    
    return 0;
}