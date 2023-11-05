#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
    int dict[26];
    for (int i=0; i<26; i++) {
        dict[i] = 0;
    }

    int len = s.length();
    if (t.length() != len) {
        return false;
    }

    for (int i=0; i<len; i++) {
        dict[s[i]-'a']++;
        dict[t[i]-'a']--;
    }

    for (int i=0; i<26; i++) {
        if (dict[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    
    return 0;
}