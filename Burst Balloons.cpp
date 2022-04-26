class Solution {
public:
    int maxCoins(vector<int>& nums) {
         nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int n = nums.size();
        int dp[n+1][n+1];
        for (int i = 0; i<=n; i++) {
            dp[i][i] = 0;
        }
        for (int L = 2; L<n; L++) {
            for (int i = 1; i<n-L+1; i++) {
                int j = i+L-1;
                dp[i][j] = INT_MIN;
                // k is for applying brackets between i and j
                // (a1,a2,a3,a4),a5
                // (a1)a2,a3,a4,a5
                // similarly applying bracket starting from i, going till before j
                for (int k = i; k<j; k++) {
                    int cost = dp[i][k]+dp[k+1][j] + (nums[i-1]*nums[k]*nums[j]);
                    dp[i][j] = max(dp[i][j], cost);
                }
            }
        }
        return dp[1][n-1];
    }
};
