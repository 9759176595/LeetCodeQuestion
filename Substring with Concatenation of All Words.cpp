class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
         int len = words.size(); // number of words to concat 
        int wordlen = words[0].size(); // size of each word
        int window_size = wordlen * len; // size of window we have to operate on
        
        unordered_map<string,int> m; // map to store given words and their frequency
        vector<int> ans; // returning variable
                
        for(auto i:words)m[i]++; // storing words in map
        
        // sliding window using i
        // plus 1in condition to consider last window if anyone is wondering
        for(int i=0;i<s.size()-window_size+1;i++) 
        {
            unordered_map<string,int> n; // map to store words in current window
            string temp = s.substr(i,window_size); // slicing current window using substring
            
            // iterating over current window and storeing words in map
            for(int j=0;j<temp.size();j+=wordlen)
            {
                string temp2 = temp.substr(j,wordlen);
                n[temp2]++; 
            }

            // if at any point maps become equal push the index in ans vector
            if(m==n)
                ans.push_back(i);
        }
        
        // return ans
        return ans;
    }
};
