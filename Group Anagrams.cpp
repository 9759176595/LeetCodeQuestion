class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> keys;
        string temp;
        for(auto i: strs){
            temp=i;
            sort(temp.begin(),temp.end());
            keys[temp].emplace_back(i);
            
        }
        for(auto i=keys.begin();i!=keys.end();i++){
            res.emplace_back(i->second);
        }
        return res;
    }
};
