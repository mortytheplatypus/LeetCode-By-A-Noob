// https://leetcode.com/problems/add-two-numbers/description/

#include <bits/stdc++.h>
using namespace std;


//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print(ListNode* l) {
    while (l != nullptr) {
        cout << l->val << " ";
        l = l->next;
    }

    cout << "\n";
}

ListNode* deleteLastElement(ListNode* l) {
    ListNode* root = l;
    while (l->next->next != nullptr) {
        l = l->next;
    }

    l->next = nullptr;
    return root;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* root = new ListNode(0);
    ListNode* l = root;

    while (l1 != nullptr && l2 != nullptr) {
        l->val = (l1->val + l2->val);
        l->next = new ListNode(0);
        l = l->next;
        l1 = l1->next;
        l2 = l2->next;
    }

    while (l1 != nullptr) {
        l->val = l1->val;
        l->next = new ListNode(0);
        l = l->next;
        l1 = l1->next;
    }

    while (l2 != nullptr) {
        l->val = l2->val;
        l->next = new ListNode(0);
        l = l->next;
        l2 = l2->next;
    }
    
    l = root;
    int carry = 0;
    while (l->next != nullptr) {
        l->val += carry;
        if (l->val > 9) {
            carry = 1;
        } else {
            carry = 0;
        }

        l->val %= 10;

        // cout << l->val << " ";
        l = l->next;
    }
    
    l->val += carry;
    if (l->val == 0) {
        root = deleteLastElement(root);
    }

    return root;  
}

void print(ListNode* l1, ListNode* l2) {
    ListNode* l;

    l = l1;
    while (l != nullptr) {
        cout << l->val << " ";
        l = l->next;
    }

    cout << "\n";

    l = l2;
    while (l != nullptr) {
        cout << l->val << " ";
        l = l->next;
    }

    cout << "\n";
}



int main() {
    vector<int> v1 = {0};
    vector<int> v2 = {0};

    ListNode* l;

    ListNode* l1 = new ListNode(v1[0]);
    l = l1;

    for (int i = 1; i < v1.size(); i++) {
        l->next = new ListNode(v1[i]);
        l = l->next;
    }

    ListNode* l2 = new ListNode(v2[0]);
    l = l2;

    for (int i = 1; i < v2.size(); i++) {
        l->next = new ListNode(v2[i]);
        l = l->next;
    }

    // print(l1, l2);

    l = addTwoNumbers(l1, l2);
    print(l);
    return 0;
}