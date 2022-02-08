class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        map<int,int> m;
        int t=0;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
            if(m[nums[i]]>1){
                t=nums[i];
                break;
            }
                
            
        }
        return t;
    }
};
