class Solution {
public:
    int search(vector<int>& nums, int target) {
        int min=nums[0];
        int idx=0;
        
        for(int i=0;i<nums.size();i++){
            if(min>nums[i]){
                min=nums[i];
                idx=i;
                 
            }
            if(nums[i]==target)
                   return i;
        }
       
       // else
            return -1;
    }
};
