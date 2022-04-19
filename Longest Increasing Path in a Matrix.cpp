class Solution {
public:
     int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j, int last){
        if(i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size() || matrix[i][j] <= last)
            return 0;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] =  1+max({
                        dfs(matrix,dp,i+1,j,matrix[i][j]),
                        dfs(matrix,dp,i-1,j,matrix[i][j]),
                        dfs(matrix,dp,i,j+1,matrix[i][j]),
                        dfs(matrix,dp,i,j-1,matrix[i][j]),
                     });
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(!matrix.size()) return 0;
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),-1));
        int ans = 0;
        for(int i=0;i<matrix.size();++i){
            for(int j=0;j<matrix[0].size();++j){
                ans = max(ans, dfs(matrix, dp, i, j, INT_MIN));
            }
        }
        return ans;
    }
};
