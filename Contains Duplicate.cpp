class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;  //map[nums[i]]==key  ++=counting
        }
        for(auto i=mp.begin();i!=mp.end();i++){
            if(i->second > 1)
                return 1;
        }
        return 0;
    }
};
