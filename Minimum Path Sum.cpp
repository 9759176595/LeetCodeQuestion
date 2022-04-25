class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row=grid.size();
        if(row==0)
            return 0;
        int cols=grid[0].size();
        vector<vector<int>>dp(row,vector<int>(cols,0));
        int i,j;
        dp[0][0]=grid[0][0];
        //1st row
        for(int i=1;i<cols;i++){
            dp[0][i]=dp[0][i-1]+grid[0][i];
        }
        //1st column filling
        for(int i=1;i<row;i++){
            dp[i][0]=dp[i-1][0]+grid[i][0];
        }
        //now fill rest of cell
        for(int i=1;i<row;i++){
            for(int j=1;j<cols;j++){
                dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[row-1][cols-1];
    }
};
