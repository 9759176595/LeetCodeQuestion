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
    // Prune children of the tree recursively. The only decisions at each node are whether to prune the left child or the right child.
    
    // Time Complexity: O(N)O(N)
    // Space Complexity: O(N)O(N),
    TreeNode* pruneTree(TreeNode* root) {
        if (root == NULL) return NULL;
    
            root->left = pruneTree(root->left);
            root->right = pruneTree(root->right);
   
            if (root->val == 0 && root->left == NULL && root->right == NULL) root = NULL;
    
            return root;
    }
};
