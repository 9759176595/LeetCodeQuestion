class Solution {
public:
    bool isMatch(string s, string p) {
         int n = s.length();
        int m = p.length();
        if(m==0)
            return (n==0);
        bool dp[n+1][m+1];
        memset(dp,false,sizeof(dp));
        dp[0][0]=true;
        for(int j=1;j<m+1;j++){
            if(p[j-1]=='*')
                dp[0][j]=dp[0][j-1];
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(p[j-1]=='*')
                    dp[i][j]=dp[i][j-1]||dp[i-1][j];
                else if(p[j-1]=='?' || p[j-1]==s[i-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                    dp[i][j]=false;
            }
        }
        return dp[n][m];
    }
};
