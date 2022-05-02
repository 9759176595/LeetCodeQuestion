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
    int lc=0;
    int rc=0;
    int countNode(TreeNode* root,int x){
        if(root==NULL) return 0;
        int left=countNode(root->left,x);
        int right=countNode(root->right,x);
        
        if(root->val==x){
            lc=left;
            rc=right;
            
        }
        return left+right+1;
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        lc=0;
        rc=0;
        countNode(root,x);
        int nnpex=n-(lc+rc+1);
        //nnpex no of node in parent excluding x
        int maxCount=max(nnpex,max(lc,rc));
        if(maxCount>n/2){
            return true;
        }
        return false;
    }
};
