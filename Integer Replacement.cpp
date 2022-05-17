class Solution {
    unordered_map<int, int> dp;
    int helper(long long n)
    {
        if(n == 1) 
            return 0;
        if(dp[n]) 
            return dp[n];
        if(n%2)
            return dp[n] = 1 + min(helper(n-1), helper(n+1));
        else
            return dp[n] = 1 + helper(n/2);
    }
public:
    int integerReplacement(int n) {
     return helper(n);
    }
};
