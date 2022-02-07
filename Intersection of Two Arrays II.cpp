class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
       map<int,int> m1;
        map<int,int> m2;
        vector<int> v;
        for(int i=0;i<nums1.size();i++){
            m1[nums1[i]]++;
        }
         for(int i=0;i<nums2.size();i++){
            m2[nums2[i]]++;
        }
        for(auto i: m1){
            int x=min(i.second,m2[i.first]);
                for(int j=0;j<x;j++){
                    v.push_back(i.first);
                }
        }
        return v;
    }
};
