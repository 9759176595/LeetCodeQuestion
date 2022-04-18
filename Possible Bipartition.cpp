class Solution {
public:
     bool dfs(int node, vector<int> adj[], vector<int>& color)
    {
        for(auto nd: adj[node])
        {
            if(color[nd] == -1)
            {   
                color[nd] = 1 - color[node];      //color the adjacent vertices of node with the color opposite to the color of node if(0 -then--> 1 or 1 -then-->0)
                if(!dfs(nd, adj, color)) return false;
            }
            else if(color[nd] == color[node])       //If color of two adjacent node is same return false as we can't color the graph in exatly two color
                return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
         vector<int> adj[n+1];
        
        for(auto edge:dislikes)  //Creating graph
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> color(n+1, -1);
        
        for(int i=1; i<=n; i++)
        {
            if(color[i] == -1)
            {   
                color[i] = 0;                                    //Initially we start with color 0 you can start with 1 also
                if(!dfs(i, adj, color)) return false;
            }
        }
        
        return true;
    }
};
