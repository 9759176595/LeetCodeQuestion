class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //optimal solution O(1)
      int n=nums.size();
        vector<int>res(n);
        res[0]=nums[0];
        for(int i=1;i<n;i++){
            res[i]=res[i-1]*nums[i];
        }
        res[n-1]=res[n-2];
        int r=1;
        for(int i=n-1;i>0;i--){
            res[i]=res[i-1]*r;
            r*=nums[i];
        }
        res[0]=r;
        return res;
    }
};
