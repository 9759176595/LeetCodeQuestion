class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
           int n = nums.size();
        int lis[n];
        int lds[n];
        lis[0] = 1;
        for(int i = 1;i<n;i++){
            lis[i] = 1;
            for(int j = 0;j<i;j++){
                if(nums[j]<nums[i]){
                    lis[i] = max(lis[i],lis[j]+1);
                }
            }
        }
        lds[n-1] = 1;
        for(int i = n-2;i>=0;i--){
            lds[i] = 1;
            for(int j = n-1;j>i;j--){
                if(nums[j] < nums[i]){
                    lds[i] = max(lds[i],lds[j]+1);
                }
            }
        }
        int res = INT_MIN;
        for(int i = 0;i<n;i++){
             if(lis[i]==1 || lds[i]==1){
                continue;
            }
            res = max(res,lis[i] + lds[i]-1);
        }
        return n-res;
    }
};
