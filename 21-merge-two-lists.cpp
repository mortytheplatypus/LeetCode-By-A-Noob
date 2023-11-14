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

// ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//     if (!list1) {
//         return list2;
//     } else if (!list2) {
//         return list1;
//     }

//     ListNode* head;
//     ListNode* node;
//     ListNode* node1 = list1;
//     ListNode* node2 = list2;

//     if (node1->val < node2->val) {
//         head = node1;
//         node1 = node1->next;
//     } else {
//         head = node2;
//         node2 = node2->next;
//     }

//     node = head;
//     while (node1 && node2) {
//         if (node1->val < node2->val) {
//             node->next = node1;
//             node1 = node1->next;
//         } else {
//             node->next = node2;
//             node2 = node2->next;
//         }
//         node = node->next;
//     }

//     while (node1) {
//         node->next = node1;
//         node1 = node1->next;
//     }

//     while (node2) {
//         node->next = node2;
//         node2 = node2->next;
//     }
    
//     return head;
// }


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(list1 == NULL){
        return list2;
    }

    if(list2 == NULL){
        return list1;
    }

    if(list1 -> val <= list2 -> val){
        list1 -> next = mergeTwoLists(list1 -> next, list2);
        return list1;
    } else { 
        list2 -> next = mergeTwoLists(list1, list2 -> next);
        return list2;
    }
}

int main() {
    //
    
    return 0;
}