class Solution {
public:
    int countWords(vector<string>& word1, vector<string>& word2) {
        map<string,int> mp1;
        map<string,int> mp2;
        
        for(int i=0;i<word1.size();i++){
            mp1[word1[i]]++;
        }
        for(int i=0;i<word2.size();i++){
            mp2[word2[i]]++;
        }
        int cnt=0;
        for(int i=0;i<word1.size();i++){
            auto j=find(word2.begin(),word2.end(),word1[i]);
            if(j!=word2.end()){
                if(mp1[word1[i]]==1 && mp2[word1[i]]==1)
                    cnt++;
            }
                
        }
        return cnt;
    }
};
