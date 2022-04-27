class Solution {
public:
//     vector<vector<int>>dp;
//     int numDistinct(string s, string t) {
//         int n=s.size();
//         int m=t.size();
//         int i=0, j=0;
//         dp.resize(n,vector<int>(m,-1));
//         return choices(s,t,n,m,i,j);
//     }
//     int choices(string s, string t,int n, int m, int i, int j){
//          //base case
//         if(j==m) return 1;
//         if(i==n) return 0;  //end me pahuch gye
        
        
//         if(dp[i][j]!=-1) return dp[i][j];
//         if(s[i]==t[j])
//          return dp[i][j] =choices(s,t,n,m,i+1,j+1)+choices(s,t,n,m,i+1,j);
//         else
//            return dp[i][j] = choices(s,t,n,m,i+1,j);
        
        int numDistinct(string s, string t) {
            int n=t.size();
            int m=s.size();
            vector<vector<unsigned long long>>dp(n+1,vector<unsigned long long>(m+1,0));
            for(int j=0;j<=m;j++)
                dp[0][j]=1;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(t[i-1]==s[j-1])
                        //match
                        dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
                    else //dont match
                        dp[i][j]=dp[i][j-1];
                }
            }
        
    return dp[n][m];
    }
};
