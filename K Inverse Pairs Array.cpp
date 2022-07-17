// Approach 1: DP [1]
// Iteration equation:
// dp[n][k] = dp[n - 1][k] + dp[n - 1][k-1] + ... + dp[n - 1][k - n + 1]
const int mod = 1e9 + 7, N = 1001;
class Solution {
    int dp[N][N] = {};
public:
    int kInversePairs(int n, int K) {
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++ i){
            long long x = 0; 
            for (int j = 0; j <= K; ++ j){
                x += dp[i - 1][j];
                if (j >= i)
                    x -= dp[i - 1][j - i];
                dp[i][j] = ((long long)dp[i][j] + x) % mod; 
            }
        }
        return dp[n][K];
    }
};
