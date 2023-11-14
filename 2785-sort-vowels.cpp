#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'o'|| c == 'u'|| c == 'i' 
        || c == 'A' || c == 'E' || c == 'O'|| c == 'U'|| c == 'I';
}

// string sortVowels(string s) {
//     unordered_set<char> vowels = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
//     priority_queue<char, vector<char>, greater<char>> pq;
//     string t = "";
    
//     for (auto c : s) {
//         if (isVowel(c)) {
//             pq.push(c);
//         }
//     }

//     if (pq.empty()) {
//         return s;
//     }

//     for (auto c : s) {
//         if (isVowel(c)) {
//             t += pq.top();
//             pq.pop();
//         } else {
//             t += c;
//         }
//     }

//     return t;
// }

string sortVowels(string s) {
    string vowels = "", t = "";

    for (char c : s) {
        if (isVowel(c)) {
            vowels += c;
        }
    }

    sort(vowels.begin(), vowels.end(), greater<char>());

    for (char c : s) {
        if (isVowel(c)) {
            t += vowels.back();
            vowels.pop_back();
        } else {
            t += c;
        }
    }

    return t;
}

int main() {
    string s = "lEetcOde";
    cout << sortVowels(s) << endl;
    
    return 0;
}