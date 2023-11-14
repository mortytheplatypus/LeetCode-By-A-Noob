#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode* head) {
    ListNode* node = head;
    while (node) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

// ListNode* reverseList(ListNode* head) {
//     if (!head) {
//         return nullptr;
//     }
//     vector<ListNode*> v;
//     ListNode* node = head;

//     while (node) {
//         v.push_back(node);
//         node = node->next;
//     }
    
//     ListNode* reverseHead = new ListNode(v.back()->val);
//     v.pop_back();

//     node = reverseHead;
//     while (!v.empty()) {
//         node->next = new ListNode(v.back()->val);
//         v.pop_back();
//         node = node->next;
//     }

//     return reverseHead;
// }

ListNode* reverseList(ListNode* head) { 
    ListNode* prev=nullptr;
    ListNode* curr=head;
    
    while (curr) {
        ListNode* next=curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

int main() {
    ListNode* head = new ListNode(1);
    ListNode* node = head;
    node->next = new ListNode(2);
    node = node->next;
    node->next = new ListNode(3);
    node = node->next;

    ListNode* reverseHead = reverseList(head);
    printList(reverseHead);
    
    return 0;
}