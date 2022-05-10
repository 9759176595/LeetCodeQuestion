class Solution {
public:
    int thirdMax(vector<int>& nums) {
       sort(nums.begin(),nums.end());
        vector<int> temp;
        int j=0,i,n;
        for(i=0;i<nums.size()-1;i++)
        {
            if(nums[i]!=nums[i+1])    //remove all duplicates
            {
                temp.push_back(nums[i]);  
            }
                
        }
        temp.push_back(nums[nums.size()-1]);    //sorted vector of all unique elements
        n=temp.size();
        
        if(n <= 2)
            return temp[n-1];  //return last element
        return temp[n-3];   //return third last element 
    }
};
