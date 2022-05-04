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
     unordered_map<int,int>mp1,mp2;
    TreeNode*solve(vector<int>& pre, vector<int>& post,int s1,int e1,int s2,int e2){
        if(s1 == e1) return new TreeNode(pre[s1]);
        else if(s1>e1) return NULL;
        TreeNode*res = new TreeNode(pre[s1]);
        if(pre[s1+1] != post[e2-1]){
            res->left = solve(pre,post,s1+1,mp1[post[e2-1]]-1,s2,mp2[pre[s1+1]]);
            res->right = solve(pre,post,mp1[post[e2-1]],e1,mp2[pre[s1+1]]+1,e2-1);
        }
        else{
            res->left = solve(pre,post,s1+1,e1,s2,e2-1);
        }
        return res;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for(int i = 0;i<preorder.size();i++){
            mp1[preorder[i]] = i;
            mp2[postorder[i]] = i;
        }
        return solve(preorder,postorder,0,preorder.size()-1,0,postorder.size()-1);
    }
};
