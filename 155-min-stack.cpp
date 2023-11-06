#include <bits/stdc++.h>
using namespace std;

/*

      v: 7->6->2->1->3->5->4
    min: 7->6->2->1 

*/

class MinStack {
    vector<int> mainStack;
    vector<int> minStack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        mainStack.push_back(val);

        if (minStack.empty() || val <= minStack.back()) {
            minStack.push_back(val);
        }
    }
    
    void pop() {
        if (mainStack.back() == minStack.back()) {
            minStack.pop_back();
        }
        mainStack.pop_back();
    }
    
    int top() {
        return mainStack.back();
    }
    
    int getMin() {
        return minStack.back(); 
    }
};

int main() {
    return 0;
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */