class Solution {
public:
    int countGoodSubstrings(string s) {
        int res=0;
        if(s.size()-1<=1) return 0;
        for(int i=0;i<s.size()-2;i++){
            if(s[i]==s[i+1]|| s[i+1]==s[i+2] || s[i+2]==s[i])
                continue;
            res++;
        }
        return res;
    }
};
