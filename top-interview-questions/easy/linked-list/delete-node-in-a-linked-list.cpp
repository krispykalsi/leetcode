//
// Created by I$K on 23/09/21.
//

#include "list-node.cpp"

class Solution {
public:
    void deleteNode(ListNode* node) {
        auto nextVal = node->next->val;
        node->val = nextVal;
        auto temp = node->next;
        node->next = temp->next;
        delete temp;
    }
};
