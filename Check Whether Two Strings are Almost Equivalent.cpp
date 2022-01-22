class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        map<char,int> mp1;
         map<char,int> mp2;
      
        for(int i=0;i<word1.length();i++){
            mp1[word1[i]]++;
        }
         for(int i=0;i<word2.length();i++){
            mp2[word2[i]]++;
        }
        for(char i='a'; i<='z';i++){
            if(abs(mp1[i]-mp2[i])<=3)
                continue;
            else
                return 0;
        }
        
        
        return 1;
    }
};
