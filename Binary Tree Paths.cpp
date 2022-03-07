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
    void pathfinder(TreeNode* root, vector<string>&res,string currpath){
        if(root==NULL){
            return;
        }
        //if leaf then add its value to currPath
        if(root->left==NULL && root->right==NULL){
            currpath+=to_string(root->val);
            res.push_back(currpath);
            return;
        }
        //else add the node's value to path
        currpath+=to_string(root->val)+"->";
        
        if(root->left) pathfinder(root->left,res,currpath);
         if(root->right) pathfinder(root->right,res,currpath);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>res;
        pathfinder(root,res,"");
        return res;
    }
};
