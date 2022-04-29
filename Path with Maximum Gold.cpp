class Solution {
public:
    int solve(int i,int j,int m,int n,vector<vector<int>> &grid,vector<vector<bool>> &vis){
        if(i < 0 or i >= m) return 0;
        else if(j < 0 or j >= n) return 0;
        else if(!grid[i][j]) return 0;
        else if(vis[i][j]) return 0;
        
        vis[i][j] = true;
        
        int up = solve(i-1,j,m,n,grid,vis);
        int down = solve(i+1,j,m,n,grid,vis);
        int left = solve(i,j-1,m,n,grid,vis);
        int right = solve(i,j+1,m,n,grid,vis);
        
        vis[i][j] = false;
        
        int ans = grid[i][j] + max({up,down,left,right});
        return ans;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int maxGold = 0;
        vector<vector<bool>> vis(m+1,vector<bool> (n+1));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!grid[i][j]) continue;
                int currGold = solve(i,j,m,n,grid,vis);
                maxGold = max(maxGold,currGold);
            }
        }
        
        return maxGold;
    }
};
