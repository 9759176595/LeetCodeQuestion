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
    vector<double> averageOfLevels(TreeNode* root) {
      vector<double>c;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            double size=q.size();
            double f=0,f1;
            for(int i=0;i<size;i++){
                TreeNode* tmp=q.front();
                q.pop();
                f=f+tmp->val;
                
                if(tmp->left!=NULL)
                    q.push(tmp->left);
                if(tmp->right!=NULL)
                    q.push(tmp->right);
            }
            f1=f/size;
            c.push_back(f1);
        }
        return c;
    }
};
