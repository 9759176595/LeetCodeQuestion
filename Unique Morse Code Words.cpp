class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string>v={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string>ans;
        for(auto x: words){
            string res="";
            for(auto ch: x)
                res+=v[ch-'a'];
           ans.insert(res); 
        }
        return ans.size();
    }
};
