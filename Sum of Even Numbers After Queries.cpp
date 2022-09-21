class Solution {
public:
     static bool is_even(int x) {
        return !(x & 1);
    }
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
          int sum = accumulate(begin(nums), end(nums), 0, [](int sum, int x) {
            return is_even(x) ? sum + x : sum; });

        vector<int> ans;
        ans.reserve(size(queries));
        for (const vector<int>& query : queries) {
            const int val = query[0];
            const int index = query[1];
            
            int& num = nums[index];
            
            if (is_even(num)) sum -= num;
            num += val;
            if (is_even(num)) sum += num;
            
            ans.push_back(sum);
        }
        return ans;
    }
};
