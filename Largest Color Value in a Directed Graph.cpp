class Solution {
public:
  
         int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = (int)colors.size();
        int m = (int)edges.size();
        vector<vector<int>> G = vector<vector<int>>(n);
        
        // Count indegree as per kahns algo
        vector<int> inDeg(n, 0);
        for (auto e : edges) {
            G[e[0]].push_back(e[1]);
            inDeg[e[1]]++;
        }
        
        // Push all nodes with 0 in degree
        queue<int> Q;
        for (int u = 0; u < n; u++)
            if (inDeg[u] == 0) Q.push(u);
        
        vector<vector<int>> colorCount(n, vector<int>(26, 0));
        
        int ret = 0;
        int visited = 0;
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            
            colorCount[u][colors[u]-'a']++;
            ret = max(ret, colorCount[u][colors[u]-'a']);
            
            for (int v : G[u]) {
                inDeg[v]--;
                if (inDeg[v] == 0) Q.push(v);
                for (int i = 0; i < 26; i++) 
                    colorCount[v][i] = max(colorCount[u][i], colorCount[v][i]);
            }
            
            visited++;
        }
        
        if (visited != n) return -1;
        
        return ret;
    }
};
