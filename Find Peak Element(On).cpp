class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int t=nums.size();
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]>nums[j])
                    return i;
                else if(nums[t-1]>nums[t-2])
                    return t-1;
                else if(nums[j]>nums[j-1] && nums[j]>nums[j+1])
                    return (j);
            }
        }
        return 0;
    }
};
