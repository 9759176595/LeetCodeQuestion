class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int mask=0;                             // stores the answer
        for (int i=0;i<32;i++)                  
        {
            int c=0;                            // Count for how many elements ith bit is set
            for (int j=0;j<nums.size();j++)
            {
                if (nums[j]&(1<<i)) c++;        // Check if ith bit is set in nums[j], c++;
            }
             // If the count of element whose ith bit is set is not a multiple of 3 means the element
            //  which appears once has the ith bit set, hence setting the ith bit in mask[answer]. 
            if (c%3!=0) mask = mask | 1<<i;    
        }
        return mask; 
    }
};
