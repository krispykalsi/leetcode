//
// Created by I$K on 28/09/21.
//

#include "tree-node.cpp"
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }
        queue<TreeNode *> q;
        q.push(root);
        int nodesInCurrentLevel = 1;
        for (int i = 0; !q.empty(); ++i) {
            vector<int> level;
            int nodesInNextLevel = 0;
            for (int j = 0; !q.empty() && j < nodesInCurrentLevel; ++j) {
                auto node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left != nullptr) {
                    q.push(node->left);
                    ++nodesInNextLevel;
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                    ++nodesInNextLevel;
                }
            }
            if (!level.empty()) {
                ans.push_back(level);
            }
            nodesInCurrentLevel = nodesInNextLevel;
        }
        return ans;
    }
};
