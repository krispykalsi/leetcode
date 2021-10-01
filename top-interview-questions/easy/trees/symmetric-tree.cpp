//
// Created by I$K on 27/09/21.
//

#include "tree-node.cpp"
#include <vector>
#include <optional>

using namespace std;

class Solution {
    void traversePreOrder(TreeNode *node, vector<optional<int>> &array) {
        if (node == nullptr) {
            array.emplace_back(nullopt);
            return;
        }
        array.emplace_back(node->val);
        traversePreOrder(node->left, array);
        traversePreOrder(node->right, array);
    }

    void traversePostOrder(TreeNode *node, vector<optional<int>> &array) {
        if (node == nullptr) {
            array.emplace_back(nullopt);
            return;
        }
        traversePostOrder(node->left, array);
        traversePostOrder(node->right, array);
        array.emplace_back(node->val);
    }
public:
    bool isSymmetric(TreeNode *root) {
        vector<optional<int>> pre, post;
        traversePreOrder(root, pre);
        traversePostOrder(root, post);
        const auto SIZE = pre.size();
        for (int i = 0; i < SIZE; ++i) {
            if (*pre[i] != *post[(SIZE-1) - i]) {
                return false;
            }
        }
        return true;
    }
};
