#include <bits/stdc++.h>
using namespace std;

int countCharacters(vector<string>& words, string chars) {
    unordered_map<char, int> mp;
    for (char c : chars) {
        mp[c]++;
    }

    for (auto it : mp) {
        cout << it.first << " " << it.second << "\n";
    }

    int count = 0, n = words.size();

    for (int i = 0; i < n; i++) {
        unordered_map<char, int> temp = mp;
        bool flag = true;
        for (char c : words[i]) {
            if (temp.find(c) == temp.end() || temp[c] == 0) {
                flag = false;
                break;
            } else {
                temp[c]--;
            }
        }
        if (flag) {
            count += words[i].size();
        }
    }

    return count;
}

int main() {
    vector<string> words = {"cat","bt","hat","tree"};
    string chars = "atach";

    cout << countCharacters(words, chars) << "\n";

    return 0;
}

