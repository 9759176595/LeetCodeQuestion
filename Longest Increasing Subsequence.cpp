class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
         int n = nums.size();
        vector<int> v;
        int max_1 = INT_MIN;
        for(int i = 0; i < n; i++){
            if(i == 0)
                v.push_back(nums[i]);
            else{
                auto x = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
                if(x >= v.size())
                    v.push_back(nums[i]);
                else
                v[x] = nums[i];
            }    
        }
        return v.size();
    }
};
