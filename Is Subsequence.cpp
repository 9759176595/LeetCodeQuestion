class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0, j=0;
        if(s.size()<=0)
            return 1;
        for(int j=0;j<t.size();){
            if(s[i]==t[j]){
                i++;
                j++;
                if(i>=s.size()) return true;
            }
            else{
                j++;
            }
        }
        return 0;
    }
};
