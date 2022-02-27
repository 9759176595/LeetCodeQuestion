/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, unsigned long long int>> q;
        q.push({root, 1});

        int width = 0;
        while (!q.empty()) {
            auto left = q.front().second;
            auto right = left;

            int size = q.size();
            while (size-- > 0) {
                auto [node, index] = q.front(); q.pop();

                right = index;

                if (node->left) q.push({node->left, 2 * index});
                if (node->right) q.push({node->right, 2 * index + 1});
            }
            width = max(width, int(right - left + 1));
        }
        return width;
    }
};
