class Solution {
public:
    void findCombination(vector<int>& arr, int idx, int target, vector<vector<int>> &ans,vector<int> &ds)
    {       
        if(target==0)
        {
            ans.push_back(ds);
            return;
        }
        
        for(int i=idx;i<arr.size();i++)
        {
            if(i>idx && arr[i]==arr[i-1])
                continue;
        
            if(arr[i]>target)
                break;

            ds.push_back(arr[i]);
            findCombination(arr,i+1,target-arr[i],ans,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       vector<vector<int>> ans;
        vector<int> ds;
        
        sort(candidates.begin(),candidates.end());
        
        findCombination(candidates,0,target,ans,ds);
        
        return ans; 
    }
};
