class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                cnt+=abs(nums[i]-nums[j])==k;
            }
                
        }
        return cnt;
    }
};
