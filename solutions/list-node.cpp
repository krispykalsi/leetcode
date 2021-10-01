//
// Created by I$K on 23/09/21.
//
#include <initializer_list>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
    explicit ListNode(int x, ListNode *nxt) : val(x), next(nxt) {}
    explicit ListNode(int x, std::initializer_list<int> nums) : val(x) {
        auto temp = this;
        for (auto num: nums) {
            temp -> next = new ListNode(num);
            temp = temp -> next;
        }
    }

    void print(int upto = -1) const {
        std::cout << val;
        auto temp = next;
        if (upto < 0) {
            while (temp != nullptr) {
                std::cout << " -> " << temp -> val;
                temp = temp -> next;
            }
        } else {
            while (temp != nullptr && upto > 0) {
                std::cout << " -> " << temp -> val;
                temp = temp -> next;
                --upto;
            }
        }
        if (temp == nullptr) {
            std::cout << " -> NULL\n";
        } else {
            std::cout << " ...\n";
        }
    }

    void introduceCycleAt(int position) {
        const auto OUT_OF_RANGE = "Couldn't form cycle (index out of range)\n";
        if (position < 0) {
            std::cout << OUT_OF_RANGE;
            return;
        }

        auto temp = this;
        while (position > 0 && temp->next != nullptr) {
            temp = temp->next;
            --position;
        }

        if (position > 0) {
            std::cout << OUT_OF_RANGE;
            return;
        }

        auto end = temp;
        while (end->next != nullptr) {
            end = end->next;
        }
        end->next = temp;
    }

    static ListNode *getEndNodeIfHasCycle(ListNode *head) {
        auto dummy = new ListNode(-1, head);
        auto slow = dummy;
        auto fast = dummy;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                break;
            }
        }

        if (fast != nullptr) {
            if (fast->next == nullptr) {
                delete dummy;
                return nullptr;
            } else {
                slow = dummy;
                while (slow->next != fast->next) {
                    slow = slow->next;
                    fast = fast->next;
                }
                delete dummy;
                return fast;
            }
        }
        return nullptr;
    }

    static void destroy(ListNode* head) {
        auto cycleEnd = getEndNodeIfHasCycle(head);
        if (cycleEnd != nullptr) {
            while (head != cycleEnd) {
                auto temp = head->next;
                delete head;
                head = temp;
            }
            delete head;
        } else {
            while (head != nullptr) {
                auto temp = head->next;
                delete head;
                head = temp;
            }
        }
    }
};