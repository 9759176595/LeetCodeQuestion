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
    vector<vector<int>>ans;

void func(TreeNode* root,int sum,int targetSum,vector<int>&t){
    
    if(root==NULL) return;
    
    if(root->val+sum==targetSum && root->left==NULL && root->right==NULL){
        t.push_back(root->val);
        ans.push_back(t);
        t.pop_back();
        return;  
    }   
    
    t.push_back(root->val);
    func(root->left,sum+root->val,targetSum,t);
    func(root->right,sum+root->val,targetSum,t);
    t.pop_back();
}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>t;
    func(root,0,targetSum,t);
    return ans;
    }
};
