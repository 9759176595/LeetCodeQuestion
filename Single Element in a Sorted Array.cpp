class Solution {
public:
//    Time Complexity = O(LogN)
// Space Complexity = O(1)
    
    int singleNonDuplicate(vector<int>& nums) {
           int left = 0, right = nums.size()-2; 
       
        while(left <= right){
            int mid = left + (right-left)/2;
           
            if(mid%2 == 0 && nums[mid+1] == nums[mid] || 
               mid%2 == 1 && nums[mid-1] == nums[mid]) {
                left = mid+1;
            }
            else right = mid-1;
        }
        return nums[left];
    }
};
