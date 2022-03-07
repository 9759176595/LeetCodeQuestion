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
    bool ans(TreeNode* root, int currSum, int targetSum){
        if(root==NULL)
            return false;
        if(root->left==NULL && root->right==NULL ){
            return ((currSum+root->val)==targetSum);
        }
        return ans(root->left,currSum+root->val,targetSum) ||
            ans(root->right,currSum+root->val,targetSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return ans(root,0,targetSum);
    }
};
