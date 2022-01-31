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
    bool isCousins(TreeNode* root, int x, int y) {
        int px=0;
        int py=0;
        int dx=-1;
        int dy=-1;
        
        parentAndDepth(root,x,y,0,dx,dy,px,py);
        return ((dx==dy)  &&(px!=py));
    }
    void parentAndDepth(TreeNode* root, int x, int y,int d, int& dx,
                        int& dy, int& px, int& py){
        if(!root) return;
        if(root->left){
            if(root->left->val==x){
                px=root->val;
                dx=d+1;
            }else if(root->left->val==y){
                py=root->val;
                dy=d+1;
            }
        }
        if(root->right){
            if(root->right->val==x){
                px=root->val;
                dx=d+1;
            }else if(root->right->val==y){
                py=root->val;
                dy=d+1;
            }
        }
        if(dx!=-1 && dy!=-1) return;
        
        parentAndDepth(root->left,x,y,d+1,dx,dy,px,py);
        parentAndDepth(root->right,x,y,d+1,dx,dy,px,py);
    }
};
