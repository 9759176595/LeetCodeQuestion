class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        map<int, int> mp;
        for(int c: nums3)
            for(int d: nums4)
               mp[c+d]=mp[c+d]+1;
        int cnt=0;
        for(int a: nums1)
            for(int b: nums2)
                cnt+=mp[-(a+b)];
                       
        return cnt;
    }
};

///map.put(c+d,map.getOrDefault(c+d,0)+1)==map[c+d]=map[c+d]+1
       //java                            == C++
