//
// Created by I$K on 26/09/21.
//

#include "tree-node.cpp"

class Solution {
public:
    bool isValidBST(TreeNode* root, TreeNode* min = nullptr, TreeNode* max = nullptr) {
        if (root == nullptr) {
            return true;
        }

        if (max != nullptr && root->val >= max->val) {
            return false;
        }
        if (min != nullptr && root->val <= min->val) {
            return false;
        }

        bool isRightSideValid = isValidBST(root->right, root, max);
        bool isLeftSideValid = isValidBST(root->left, min, root);
        return isLeftSideValid && isRightSideValid;
    }
};
