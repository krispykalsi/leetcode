//
// Created by I$K on 24/09/21.
//

#include "list-node.cpp"

class Solution {
    ListNode *reverse(ListNode *head) {
        if (head == nullptr) {
            return head;
        }

        auto next = head->next;
        head->next = nullptr;
        while (next != nullptr) {
            auto nextNext = next->next;
            next->next = head;
            head = next;
            next = nextNext;
        }
        return head;
    }
public:
    bool isPalindrome(ListNode* head) {
        if (head->next == nullptr) {
            return true;
        }

        auto dummy = new ListNode(-1, head);
        auto slow = dummy;
        auto fast = dummy;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        auto secondHalf = reverse(slow->next);
        auto firstHalf = head;

        while (secondHalf != nullptr) {
            if (secondHalf->val != firstHalf->val) {
                return false;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        delete dummy;
        return true;
    }
};
