class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
         int n=nums.size();
        int sum=0;
        unordered_map<int,int> mp={{0,-1}};
        for(int i=0;i<n;i++)
        {
            sum=(sum+nums[i]%k)%k;
            if(mp.count(sum)==0)
                mp[sum]=i;
            if(i-mp[sum]>1)
                return 1;
        }
        return 0;
    }
};
