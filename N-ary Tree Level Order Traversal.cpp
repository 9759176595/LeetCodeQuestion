/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (!root) return res;
        
        queue<Node *> q;
        q.push(root);
        
        Node *temp;
        
        while (!q.empty())
        {
            vector<int> row;
            int size = q.size();
            
            for (int i = 0; i < size; i++)
            {
                temp = q.front();
                q.pop();
                row.push_back(temp->val);
                
                for (int i = 0; i < temp->children.size(); i++)
                {
                    if (temp->children[i]) q.push(temp->children[i]);
                }
            }
            
            res.push_back(row);
        }
        
        return res;
    }
};
