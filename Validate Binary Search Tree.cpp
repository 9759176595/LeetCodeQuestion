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
    bool isSorted=true;
    long long curr=-9999999999;
    void infix(TreeNode* root){
        if(root==NULL) return;
        infix(root->left);
        if(root->val <=curr) isSorted=false;
        curr=root->val;
        
        infix(root->right);
    }
    bool isValidBST(TreeNode* root) {
       infix(root);
        return isSorted;
    }
};
