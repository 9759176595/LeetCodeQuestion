class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,-1);  //target+1 bcz 0 se start
        dp[0]=1;
        cs(nums,target,dp);
        return dp[target];
    }
    int cs(vector<int>&nums,int target,vector<int>&dp){
        if(dp[target]>-1) return dp[target];
        int count=0;
        for(int i=0;i<nums.size();i++){
            // 4-> (3,[1])
            if(nums[i]<=target)
            count+=cs(nums,target-nums[i],dp);
        }
        dp[target]=count;
        return count;
    }
};
