class Solution {
public:
    int dominantIndex(vector<int>& nums) {
       int maxValue=0;
        int secondValue=0;
        int maxIndex=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxValue){
                secondValue=maxValue;
                maxValue=nums[i];
                maxIndex=i;
            }
            else if(nums[i]<maxValue && nums[i]>secondValue){
                secondValue=nums[i];
            }
        }
        if(maxValue>=2*secondValue){
            return maxIndex;
        }
        else{
            return -1;
        }
        
    }
};
