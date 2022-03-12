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
    void swap(int *a, int *b){
        int temp=*a;
        *a=*b;
        *b=temp;
    }
    void calcPointers(TreeNode* root,TreeNode** first,TreeNode** mid, TreeNode** last,
                     TreeNode** prev){
        if(root==NULL)return;
        calcPointers(root->left,first,mid,last,prev);
        if(*prev && root->val<(*prev)->val){
            if(!*first){
                *first=*prev;
                *mid=root;  
            }
            else{
                *last=root;
            }
        }
        *prev=root;
        calcPointers(root->right,first,mid,last,prev);
    }
public:
    void recoverTree(TreeNode* root) {
        TreeNode * first,*mid,*last,*prev;
        first=NULL;
        mid=NULL;
        last=NULL;
        prev=NULL;
        
        calcPointers(root,&first,&mid,&last,&prev);
        //cAse 1
        if(first && last){
            swap(&(first->val),&(last->val));
        }
        else if(first && mid){
            swap(&(first->val),&(mid->val));
        }
    }
};
