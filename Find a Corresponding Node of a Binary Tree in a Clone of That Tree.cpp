/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        int looking_for=target->val;
        return search(cloned,looking_for);
    }
    TreeNode* search(TreeNode* cloned,int looking_for){
        if(cloned==NULL) return NULL;
        if(looking_for==cloned->val)
            return cloned;
        TreeNode* left=search(cloned->left,looking_for);
        if(left) return left;
        
         TreeNode* right=search(cloned->right,looking_for);
        if(right) return right;
        
        return NULL;
    }
};
