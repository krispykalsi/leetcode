//
// Created by I$K on 25/09/21.
//

#include "tree-node.cpp"
#include <algorithm>

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }
};
