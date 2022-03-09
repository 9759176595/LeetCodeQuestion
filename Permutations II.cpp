class Solution {
public:
    void givepermutedResult(set<vector<int>>&result,vector<int>& nums,int index){
        if(index>=nums.size()){
            result.insert(nums);
            return;
        }
        for(int j=index;j<nums.size();j++){
            swap(nums[index],nums[j]);
            givepermutedResult(result,nums,index+1);
            swap(nums[index],nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>result;
        vector<vector<int>>res;
        int index=0;
        givepermutedResult(result,nums,index);
        
        for(auto i=result.begin();i!=result.end();i++){
            res.push_back(*i);
        }
        return res;
    }
};
