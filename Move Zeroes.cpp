class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //Time O(n)   space = O(1) inspace
        int n=nums.size();
        if(n==0 || n==1){
            return;
        }
        int left=0, right=0;
        int temp;
        while(right<n){
            if(nums[right]==0)
                ++right;
            else
            {
                temp=nums[left];
                nums[left]=nums[right];
                nums[right]=temp;
                ++left;
                ++right;
            }
        }
        
        
    }
};
