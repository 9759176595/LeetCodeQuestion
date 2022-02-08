class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(2*n,0);
        for(int i=0;i<2*n;i++){
            res[i]=nums[i%n];
        }
        return res;
    }
};
