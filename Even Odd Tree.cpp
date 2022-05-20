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
    //Level order traversal
    bool isEvenOddTree(TreeNode* root) {
    vector<vector<int>>v;
    v.push_back({root->val});
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        int s=q.size();
        vector<int>temp;
        for(int i=0;i<s;i++)
        {
            root=q.front();
            q.pop();
            if(root->left)
            {
                q.push(root->left);
                temp.push_back(root->left->val);
            }
            if(root->right)
            {
                q.push(root->right);
                temp.push_back(root->right->val);
            }
        }
        if(temp.size()>0)
            v.push_back(temp);
    }
    for(int i=0;i<v.size();i++)
    {
        if(i%2==0)
        {
            if(v[i].size()==1)
                if(v[i][0]%2==0)
                    return false;
            for(int j=1;j<v[i].size();j++)
                if(v[i][j]%2==0 || (v[i][j-1]>=v[i][j]))
                    return false;
        }
        else
        {
            if(v[i].size()==1)
                if(v[i][0]%2!=0)
                    return false;
            for(int j=1;j<v[i].size();j++)
                if(v[i][j]%2!=0 || (v[i][j-1]<=v[i][j]))
                    return false;
        }
    }
    return true;
    }
};
