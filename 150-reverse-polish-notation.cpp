#include <bits/stdc++.h>
using namespace std;

/*
    {"2","1","+","3","*"}
    {"4","13","5","/","+"}
    {"10","6","9","3","+","-11","*","/","*","17","+","5","+"}
*/

int evalRPN(vector<string>& tokens) {
    vector<int> numberStack;

    for (string token : tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int b = numberStack.back();
            numberStack.pop_back();
            int a = numberStack.back();
            numberStack.pop_back();

            if (token == "+") {
                numberStack.push_back(a + b);
            } else if (token == "-") {
                numberStack.push_back(a - b);
            } else if (token == "*") {
                numberStack.push_back(a * b);
            } else if (token == "/") {
                numberStack.push_back(a / b);
            }
        } else {
            numberStack.push_back(stoi(token));
        }
    }

    return numberStack.back();
}

int main() {
    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};

    cout << evalRPN(tokens) << endl;
    
    return 0;
}