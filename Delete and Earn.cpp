class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int>dp(10001,0);
        for(auto x: nums){
            dp[x]+=x;
        }
        int val=*max_element(nums.begin(),nums.end());
        for(int i=2;i<=val;i++){
            dp[i]=max(dp[i-2]+dp[i],dp[i-1]);
        }
        return dp[val];
    }
};
