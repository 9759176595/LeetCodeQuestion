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
    int ans=0;
    
    pair<int,int>dfs(TreeNode* root){
        if(root==NULL)
            return {-1,-1};
        pair<int,int>left=dfs(root->left);
        pair<int,int>right=dfs(root->right);
        ans=max(ans,max(left.second,right.first)+1);
        return {left.second+1,right.first+1};
    }
    int longestZigZag(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
