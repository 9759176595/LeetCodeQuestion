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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>> ans;
        if(root == NULL) return ans;
        bool LtR = true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> temp;
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                }if(node->right){
                    q.push(node->right);
                }
                temp.push_back(node->val);
            }
            if(LtR){
                ans.push_back(temp);
            }else{
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);
            }
            LtR = !LtR;
        }
        return ans;
    }
};
