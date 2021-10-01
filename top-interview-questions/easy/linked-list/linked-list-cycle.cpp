//
// Created by I$K on 24/09/21.
//

#include "list-node.cpp"

class Solution {
public:
    bool hasCycle(ListNode *head) {
        auto dummy = new ListNode(-1, head);
        auto slow = dummy;
        auto fast = dummy;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        delete dummy;
        return false;
    }
};
