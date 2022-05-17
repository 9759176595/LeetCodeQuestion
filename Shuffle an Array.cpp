class Solution {
public:
     vector<int> store;
    vector<int> original;
    Solution(vector<int>& nums) {
         for(auto i : nums){
         store.push_back(i);
         original.push_back(i);
        }
    }
    
    vector<int> reset() {
         store = original;
        return store;
    }
    
    vector<int> shuffle() {
       random_shuffle(store.begin(),store.end());
        return store; 
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
