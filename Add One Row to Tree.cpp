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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
          // Edge case: insert above root
      if (depth-- == 1) {
        return new TreeNode(val, root, nullptr);
      }
      queue<TreeNode*> q;
      q.push(root);
      while (!q.empty()) {
	    // Is this the parent row of the to be inserted row?
        bool addLevel = depth-- == 1;
        size_t sz = q.size();
        for (size_t _ = 0; _ < sz; _++) {
          TreeNode* curr = q.front(); q.pop();
          if (addLevel) {
		    // Update the current nodes children
            curr->left  = new TreeNode(val, curr->left, nullptr    );
            curr->right = new TreeNode(val, nullptr   , curr->right);
            continue;
          } 
		  // Add the next row to the queue
          if (curr->left)
            q.push(curr->left);
          if (curr->right)
            q.push(curr->right);          
        }
      }
      return root;
    }
};
