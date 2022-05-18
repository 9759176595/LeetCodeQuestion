class Solution {
    void generating(const std::vector<int>& nums, int i, std::vector<int>& temp, std::set<std::vector<int>>& res)
    {
        if (temp.size() >= 2)
        {
            res.insert(temp);
        }
        
        for (int j = i; j < nums.size(); j++)
        {
            if (nums[j] >= temp.back())
            {
                temp.push_back(nums[j]);
                generating(nums, j + 1, temp, res);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        std::set<std::vector<int>> res;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            std::vector<int> temp;
            temp.push_back(nums[i]);
            generating(nums, i + 1, temp, res);
        }
        return {res.begin(), res.end()};
    }
};
