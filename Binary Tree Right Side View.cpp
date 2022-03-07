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
    void viewGenerator(TreeNode* root, vector<int>&res, set<int>&s, int currLevel){
        if(root==NULL) return;
        if(s.find(currLevel)==s.end()){
            s.insert(currLevel);
            res.push_back(root->val);
        }
        viewGenerator(root->right,res, s,currLevel+1);
        viewGenerator(root->left,res, s,currLevel+1);    
        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        set<int>s;
        viewGenerator(root,res,s,0);
        return res;
    }
};
