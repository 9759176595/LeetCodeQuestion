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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(!root)
            return ans;
        
        queue<TreeNode*> mq;
        mq.push(root);
        
        while(mq.size() > 0){
            int n = mq.size();
            int max = INT_MIN;
            for(int i = 0; i < n; i++){
                root = mq.front();
                mq.pop();
                if(root->val > max)
                    max = root->val;
                
                if(root->left != NULL)
                    mq.push(root->left);
                if(root->right != NULL)
                    mq.push(root->right);
            }
            ans.push_back(max);
        }
        return ans;
    }
};
