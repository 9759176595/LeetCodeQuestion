bool cmp(vector<int> &a, vector<int> &b)
{
    return a[0] > b[0];
}
class Solution {
public:
    int find(int u, vector<int> &parent)
    {
        if(parent[u] == -1)
            return u;
        return parent[u] = find(parent[u], parent);
    }
    
    bool dsu_union(int u, int v, vector<int> &parent, vector<int> &rank)
    {
        u = find(u, parent);
        v = find(v, parent);
        
        if(u != v)
        {
            if(rank[u] > rank[v]) parent[v] = u;
            else if(rank[v] > rank[u]) parent[u] = v;
            else{
                parent[v] = u;
                rank[u]++;
            }
            return true;
        }
        return false;
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end(), cmp);

        vector<int> rank_r(n+1, 0);
        vector<int> rank_g(n+1, 0);
        vector<int> red(n+1, -1);
        vector<int> green(n+1, -1);
        int count =0;                   //Number of edges removed
        int mergeR =1;                  //Number of red edges merged
        int mergeG =1;                  //Number of green edges merged
      
        for(auto e:edges)
        {
            int type = e[0];
            int u = e[1];
            int v = e[2];
            
            if(type == 3)
            {
                bool mergedRed = dsu_union(u, v, red, rank_r);
                bool mergedGreen = dsu_union(u, v, green, rank_g);
                
                if(mergedRed) mergeR++;
                if(mergedGreen) mergeG++;
                
                if(!mergedRed && !mergedGreen) count++;
                
            }
            else if(type == 2)
            {
                bool mergedGreen = dsu_union(u, v, green, rank_g);
                
                if(mergedGreen) mergeG++;
                else count++;
                
            }
            else if(type == 1)
            {
                bool mergedRed = dsu_union(u, v, red, rank_r);
                
                if(mergedRed) mergeR++;
                else count++;
            }
            
        }
        if(mergeR != n || mergeG != n) return -1;        
        
        return count;
    }
};
