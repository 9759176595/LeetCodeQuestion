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
    int findMax(TreeNode* root, int &ans){
        if(!root) return 0;
        int left=findMax(root->left,ans);
        int right=findMax(root->right,ans);
        int straightPath=max(root->val,max(left+root->val,right+root->val));
        int curvedPath=left+right+root->val;
        ans=max(ans,max(straightPath,curvedPath));
        return straightPath;
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        findMax(root,ans);
        return ans;
    }
};
