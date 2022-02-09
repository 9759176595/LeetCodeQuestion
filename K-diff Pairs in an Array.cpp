class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
       sort(nums.begin(),nums.end());
        set<vector<int>>s;
         int cnt=0;
        for(int i=0;i<nums.size()-1;i++){
           auto j=find(nums.begin()+i+1,nums.end(),nums[i]+k);
            if(j!=nums.end())
                s.insert({nums[i],nums[i]+k});
        }
        return s.size();
    }
};
