class Solution {
public:
     long int mod = 1e9 + 7;
    long  helper(int n, int k, int target, long dp[31][1002])
    {
        if(n == 0 && target == 0)
            return 1;
        
        else if(n == 0 || target < 0)
            return 0;
        
        else if(dp[n][target] != -1)
            return dp[n][target] % mod;
        long  sum = 0;
        for(int i = 1 ; i <= k ; i ++)
        {
            sum = (sum % mod + helper(n -1, k, target - i, dp) %mod)%mod;
        }
        
        return dp[n][target]=sum % mod;
    }
    int numRollsToTarget(int n, int k, int target) {
         long dp[31][1002];
        
        for(int i = 0 ; i< 31 ; i++)
        {
            for(int j = 0;  j< 1002 ; j++)
                dp[i][j] = -1;
        }
        return helper(n, k , target, dp);
    }
};
