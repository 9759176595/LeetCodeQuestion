class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        /*
    WE SIMPLY FOLLOW MATH RULE THAT SUM OF TWO SIDE OF A TRIANGLE IS ALWAY GREATER THAN THE OTHER SIDE
*/
        //WE SORT TO GET THE LARGEST NO IN THE LAST INDEX
        sort(nums.begin(),nums.end());
        int n=nums.size();
//WE LOOP FROM THE START AND COMPARE
        for (int i =n - 1; i > 1; --i)
    //IF THE ELEMENT WE STANDING ON IS THE GREATER THAN THE SUM OF FIRST 2
            if (nums[i] < nums[i - 1] + nums[i - 2])
                //WE RETURN THE SUM
                return nums[i] + nums[i - 1] + nums[i - 2];
    //ELSE WE RETURN 0
        return 0;
    }
};
