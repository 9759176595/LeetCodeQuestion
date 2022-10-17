class Solution {
public:
    bool checkIfPangram(string s) {
        unordered_map<char,int>m;
for(auto it:s)
m[it]++;
return 26==m.size();
    }
};
