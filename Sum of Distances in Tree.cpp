class Solution {
    int size;
public:
    vector<int>ans;
    vector<int>cnt;
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        size=n;
        vector<int>adj[n];
        ans.resize(n,0);
        cnt.resize(n,1);
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        dfs(0,-1,adj); //to calculate child count and answer wrt to child   
        dfs2(0,-1,adj); // to calculate ans wr t parents
        return ans;
    }
    void dfs(int src,int par,vector<int>adj[]){
        for(auto & child: adj[src]){
            if(child!=par){
                dfs(child,src,adj);
                cnt[src]+=cnt[child];
                ans[src]+=ans[child]+cnt[child];
            }
        }
    }
    void dfs2(int src,int par,vector<int>adj[]){
        for(auto & child:adj[src]){
            if(child!=par){
                ans[child]+=(ans[src]+(size-cnt[child])-ans[child]-cnt[child]);
                dfs2(child,src,adj);
            }
        }
    }
};
