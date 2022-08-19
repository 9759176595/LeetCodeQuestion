class Solution {
public:
   unordered_map<int, int> hmap;
    bool isPossible(vector<int>& nums) {
        for(const auto& val:nums)
            hmap[val]++;
        
        for(auto val:nums){
            if(hmap[val]){
                int len = 0;
                do{
                    len++;
                    hmap[val]--;
                }while(hmap.count(val+1) && hmap[val]<hmap[val+1] && hmap[++val]);
                if(len<3)
                    return false;
            }
        }
        return true;
    }
};
