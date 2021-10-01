//
// Created by I$K on 24/09/21.
//

#include "list-node.cpp"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        } else if (l2 == nullptr) {
            return l1;
        }

        if (l1->val > l2->val) {
            return mergeTwoLists(l2, l1);
        }

        auto dummy = new ListNode(-1);
        auto curr = dummy;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        if (l1 != nullptr) {
            curr->next = l1;
        } else {
            curr->next = l2;
        }

        auto head = dummy->next;
        delete dummy;
        return head;
    }
};
