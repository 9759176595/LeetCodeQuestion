class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> s;
        for(int i=0;i<nums1.size();i++){
            if(find(nums2.begin(),nums2.end(),nums1[i])!=nums2.end())
                if(find(s.begin(),s.end(),nums1[i])==s.end())
                s.push_back(nums1[i]);
        }
        return s;
    }
};

///-----------Method2
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> m(nums1.begin(), nums1.end());
        vector<int> res;
        for (auto a : nums2)
            if (m.count(a)) {
                res.push_back(a);
                m.erase(a);
            }
        return res;
    }
};
