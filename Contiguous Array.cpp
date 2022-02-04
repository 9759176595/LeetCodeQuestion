class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mymap;
        int sum=0;
        int long_subarray=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i]==0? -1: 1;
            if(sum==0){
                if(long_subarray<i+1)
                    long_subarray=i+1;
            }
            else if(mymap.find(sum)!=mymap.end()){
                if(long_subarray<i-mymap[sum])
                    long_subarray=i-mymap[sum];
            }
            else
                mymap[sum]=i;
        }
        return long_subarray;
    }
};
