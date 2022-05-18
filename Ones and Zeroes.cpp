class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        //tabulation
         int dp[m+1][n+1];
           memset(dp, 0, sizeof(dp));
        for(auto str: strs){
            int zero =0,one=0;
              for(int i=0; i<str.length() ; i++){
            if(str[i]=='0') zero++;
            else one++;
        }
            
            for(int j=m; j>=zero; j-- ){
                for(int k=n;k>=one; k--){
                    dp[j][k] = max(dp[j-zero][k-one]+1,dp[j][k]);
                }
            }
        }
        return dp[m][n];
    }
};
