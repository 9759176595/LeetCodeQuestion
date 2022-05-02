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
  long long mod = 1e9 + 7;
    
    long long total_sum = 0;
    
    long long maxi = INT_MIN;
    
    long long find_sum(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        
        return root -> val + find_sum(root -> left) + find_sum(root -> right);
    }
    
    long long helper(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        
        int left_sum = helper(root -> left);
        
        int right_sum = helper(root -> right);
        
        int subtree_sum = left_sum + right_sum + root -> val;
        
        long long temp = subtree_sum * (total_sum - subtree_sum);
        
        maxi = max(maxi, temp);
        
        return subtree_sum;
    }
    
    int maxProduct(TreeNode* root) {
        
        total_sum = find_sum(root);
        
        helper(root);
        
        return maxi % mod;
    }
};
