//
// Created by I$K on 24/09/21.
//

#include "list-node.cpp"

class Solution {
    void deleteNextNode(ListNode* node) {
        if (node != nullptr) {
            auto temp = node->next;
            node->next = temp->next;
            delete temp;
        }
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto dummy = new ListNode(-1, head);
        auto fast = dummy;
        auto slow = dummy;

        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        deleteNextNode(slow);

        head = dummy->next;
        delete dummy;
        return head;
    }
};
