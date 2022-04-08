class Solution {
public:
    long compute_sum(vector<int>nums, int x){
        long sum=0;
        for(int n:nums)
            sum+=n/x+(n%x==0?0:1);
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        // int end=2;
        // while(compute_sum(nums,end)>threshold)
        //     end<<=1;
        //  int start=end>>1;  //    end/2
        
        int end=*max_element(nums.begin(),nums.end());
        int start=1;  //    end/2
        while(start<end){
            int mid=start+(end-start)/2;
            if(compute_sum(nums,mid)>threshold)
                start=mid+1;
            else 
                end=mid;
        }
        return start;
    }
};
