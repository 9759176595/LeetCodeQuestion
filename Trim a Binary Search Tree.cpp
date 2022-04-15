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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
       return trim(root,low,high);
    }
    TreeNode* trim(TreeNode* root, int low, int high){
        if(root==NULL)
            return NULL;
        TreeNode* leftNode=trim(root->left,low,high);
        if(leftNode!=root->left){
            root->left=leftNode;
        }
        TreeNode* rightNode=trim(root->right,low,high);
         if(rightNode!=root->right){
            root->right=rightNode;
        }
        if(root->val >high || root->val <low){
            return (root->left)?root->left:root->right;
        }
        return root;
    }
};
