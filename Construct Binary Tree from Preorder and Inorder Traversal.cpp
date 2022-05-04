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
  
       TreeNode* solve(vector<int>& pre, int preStart, int preEnd, vector<int>& in, int inStart, int inEnd, map<int, int>& mp) {
        if(preStart > preEnd or inStart > inEnd) return nullptr;
        TreeNode* root = new TreeNode(pre[preStart]);
        
        int rootIndex = mp[root->val];
        int temp = rootIndex - inStart;
        
        root->left = solve(pre, preStart+1, preStart+temp, in, inStart, rootIndex-1, mp);
        root->right = solve(pre, preStart+temp+1, preEnd, in, rootIndex+1, inEnd, mp);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        map<int, int> mp;
        for(int i = 0; i < in.size(); i++){
            mp[in[i]] = i;
        }
        return solve(pre, 0, pre.size()-1, in, 0, in.size()-1, mp);
    }
};
