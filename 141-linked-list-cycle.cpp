#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void printList(ListNode* head) {
    ListNode* node = head;
    while (node) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

// bool hasCycle(ListNode *head) {
//     unordered_set<ListNode*> s;
//     ListNode* node = head;

//     while (node) {
//         if (s.find(node) != s.end()) {
//             return true;
//         }
//         s.insert(node);
//         node = node->next;
//     }

//     return false;
// }

bool hasCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    
    return false;
}

int main() {
    ListNode* head = new ListNode(1);
    ListNode* node = head;
    for (int i = 2; i <= 5; i++) {
        node->next = new ListNode(i);
        node = node->next;
    }
    
    node = head;
    while (node) {
        cout << node << " ";
        node = node->next;
    }

    printList(head);
    
    return 0;
}