class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> mp1;
        map<char, char> mp2;
        
        
        if(s.length()!=t.length()){
            return false;
        }
        int n=s.length();
        for(int i=0;i<n;i++){
            if(mp1[s[i]]==NULL && mp2[t[i]]==NULL){
                mp1[s[i]]=t[i];
                mp2[t[i]]=s[i];
            }
            else{
                if(mp1[s[i]]!=t[i])
                    return 0;
            }
        }
        

        return 1;
    }
};
