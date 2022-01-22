class Solution {
public:
     // bool helper(int n, vector<int> &dp){
     //      if(n==0) 
     //           return false;
     //     if(dp[n]!=-1){
     //         return dp[n];
     //     }
     //       for(int i=1;i*i<=n;i++){
     //           if(!helper(n-i*i,dp))
     //               dp[n]=1;
     //               return true;
     //       }
     //     dp[n]=0;
     //       return false;
     //   }
    bool winnerSquareGame(int n) {
      vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                if(dp[i-j*j]==0){
                    dp[i]=1;
                }
            }
        }
     //   dp[1]==1, dp[2]=0 , dp[3]=1  dp[4]=1
        return dp[n];
    }
};
