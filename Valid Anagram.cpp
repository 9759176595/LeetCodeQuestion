class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s.length()==t.length()){
            if(s==t){
                return true;
            }
        }
        return false;
        
    }
};
