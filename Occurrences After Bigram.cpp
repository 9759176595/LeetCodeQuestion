class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
       vector<string> words;
        stringstream ss(text);
        string word;
        while(ss >> word){
            words.push_back(word);
        }
        
        int n = words.size();
        vector<string> res;
        for(int i = 0; i <= n - 3; i++){
            if(words[i] == first && words[i+1]==second)
                res.push_back(words[i+2]);
        }
        return res; 
    }
};
