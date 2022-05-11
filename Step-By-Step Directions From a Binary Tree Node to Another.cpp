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
    TreeNode* lca(TreeNode *root,int startValue, int destValue){
        if(!root) return NULL;
        if(root->val==startValue) return root;
        if(root->val==destValue) return root;
        auto l=lca(root->left,startValue,destValue);
        auto r=lca(root->right,startValue,destValue);
        if(l&& r) return root;
        return l!=NULL ? l:r;
    }
    int Path(TreeNode* root,int value,string &path)
    {
        if(!root)return 0;
        if(root->val==value)return 1;
        path+='L';
        auto res=Path(root->left,value,path);
        if(res) return 1;
        path.pop_back();
        path+='R';
        res=Path(root->right,value,path);
        if(res) return 1;
        path.pop_back();
        return 0;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        root=lca(root,startValue,destValue);
        string p1="",p2="";
        Path(root,startValue,p1);
        Path(root,destValue,p2);
        for(int i=0;i<p1.length();i++)
            p1[i]='U';
        p1+=p2;
        return p1;
    }
};
