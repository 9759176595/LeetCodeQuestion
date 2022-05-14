class Solution {
    int rob(vector<int>&nums,int start ,int end){
         int prevTwo=0, prevOne=0, maxi=0;
        for(int i=start;i<end;i++){
            maxi=max(prevTwo+nums[i],prevOne);
            prevTwo=prevOne;
            prevOne=maxi;
}
        return maxi;
    }
public:
    
    int rob(vector<int>& nums) {
       if(nums.size()==1) return nums[0];
        return max(rob(nums,0,nums.size()-1),rob(nums,1,nums.size()));
    }
};
