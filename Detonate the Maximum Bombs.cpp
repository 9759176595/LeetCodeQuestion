class Solution {
public:
    #define ll long long
    void dfs(int src,int& cnt,vector<int>&vis,vector<int>adj[]){
        vis[src]=1; cnt++;
        for(int x: adj[src]){
            if(vis[x]==0){
                dfs(x,cnt,vis,adj);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
         vector<int>adj[n];
        for(int i=0;i<n;i++){
            ll r1=bombs[i][2];
            ll x1=bombs[i][0], y1=bombs[i][1];
            for(int j=0;j<n;j++){
                if(i!=j){
                    ll x2=bombs[j][0],y2=bombs[j][1], r2=bombs[j][2];
                    ll dsq=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
                    ll p=r1;
                    if(dsq<=p*p){
                       // cout<<i<<" "<<j<<endl;
                        adj[i].push_back(j);
                    }
                }
            }
        }
        vector<int>vis(n);
        int ans=0;
        for(int i=0;i<n;i++){
            int cnt=0;
            dfs(i,cnt,vis,adj);
            ans=max(ans,cnt);
            fill(vis.begin(),vis.end(),0);
        }
        return ans;
    }
};
