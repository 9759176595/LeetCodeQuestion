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
    void traverse(TreeNode* root, vector<int>&t){
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL){
            t.push_back(root->val);
        }
        if(root->left!=NULL){
            traverse(root->left,t);
        }
         if(root->right!=NULL){
            traverse(root->right,t);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>a;
        vector<int>b;
        traverse(root1,a);
        traverse(root2,b);
        return a==b;
    }
};
