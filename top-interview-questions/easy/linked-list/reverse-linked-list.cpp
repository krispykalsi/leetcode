//
// Created by I$K on 24/09/21.
//

#include "list-node.cpp"

class Solution {
    ListNode *recursive(ListNode *node, ListNode *newHead = nullptr) {
        if (node == nullptr) {
            return newHead;
        }
        auto next = node->next;
        node->next = newHead;
        return recursive(next, node);
    }

    ListNode *iterative(ListNode *node) {
        if (node == nullptr) {
            return node;
        }
        auto next = node->next;
        node->next = nullptr;
        while (next != nullptr) {
            auto temp = next->next;
            next->next = node;
            node = next;
            next = temp;
        }
        return node;
    }

public:
    ListNode *reverseList(ListNode *head) {
        return recursive(head);
    }
};
