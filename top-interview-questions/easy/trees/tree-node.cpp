//
// Created by I$K on 25/09/21.
//

#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
#include <optional>

const auto null = std::nullopt;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    explicit TreeNode(const std::vector<std::optional<int>> &nums) : val(0), left(nullptr), right(nullptr) {
        const size_t SIZE = nums.size();
        if (SIZE > 0) {
            val = *nums[0];
        } else {
            return;
        }
        std::queue<TreeNode *> queue;
        queue.push(this);
        for (int i = 1; i < SIZE && !queue.empty(); ++i) {
            auto node = queue.front();
            if (nums[i].has_value()) {
                // i & 1 == odd
                if (i & 1) {
                    node->left = new TreeNode(nums[i].value());
                    queue.push(node->left);
                } else {
                    node->right = new TreeNode(nums[i].value());
                    queue.push(node->right);
                    queue.pop();
                }
            } else if (!(i & 1)) {
                queue.pop();
            }
        }
    }

    int getDepth() {
        if (!_depth.has_value()) {
            _depth = calculateDepth(this);
        }
        return _depth.value();
    }

    std::vector<std::vector<TreeNode *>> *getBFSArray() {
        if (BFSArray.empty()) {
            makeBFSArray();
        }
        return &BFSArray;
    }

    void print() {
        auto treeBFS = getBFSArray();
        int depth = getDepth();

        for (int i = 0; i < depth; ++i) {
            int spaces = (depth - i);
            int midSpaces = 1 * spaces;
            for (int j = 0; j < spaces * depth / 2 + 1; ++j) {
                std::cout << " ";
            }
            for (const auto& node: treeBFS->at(i)) {
                if (node != nullptr) {
                    std::cout << node->val;
                } else {
                    std::cout << "_";
                }
                for (int j = 0; j < midSpaces; ++j) {
                    std::cout << " ";
                }
            }
            std::cout << std::endl;
        }
    }

    ~TreeNode() {
        delete left;
        delete right;
    }

private:
    std::optional<int> _depth;
    std::vector<std::vector<TreeNode *>> BFSArray;

    int calculateDepth(TreeNode *node) {
        if (node == nullptr) {
            return 0;
        }
        return 1 + std::max(calculateDepth(node->left), calculateDepth(node->right));
    }

    void makeBFSArray() {
        std::queue<TreeNode *> q;
        q.push(this);
        int depth = getDepth();
        for (int i = 0; i < depth; ++i) {
            std::vector<TreeNode *> level;
            double levelWidth = std::pow(2, i);
            for (int j = 0; j < levelWidth; ++j) {
                auto node = q.front();
                q.pop();
                level.push_back(node);
                if (node == nullptr) {
                    q.push(nullptr);
                    q.push(nullptr);
                } else {
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            BFSArray.push_back(level);
        }
    };
};
