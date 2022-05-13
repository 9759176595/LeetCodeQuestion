class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [] (const int& num1, const int& num2){
            auto order1 = to_string(num1) + to_string(num2);
            auto order2 = to_string(num2) + to_string(num1);
          
            return order1 > order2;
        });
        
        string largestNum;
        for(auto num: nums)
        {
            largestNum += to_string(num);
        }
        
        if(largestNum[0] == '0')
        {
            return "0";
        }
        return largestNum;
    }
};
