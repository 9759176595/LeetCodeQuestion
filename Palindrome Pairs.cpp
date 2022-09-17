// Algo: 1.Reverse all the word and insert in hashmap with all its indexes
//          For each index
//          1.find all its perfixes
//          2.find all its corresponding suffixes
//          3.if prefix is palindrome
//          4.check if suffix exist in map
//          5. result-> (]mp[suffix],idx)*/
class Solution {
public:
     bool isPalindrome(string &str)
    {
        int i=0,j=str.size()-1;
        while(i<j)
        {
            if(str[i]!=str[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string,int> mp;
        for(int i=0;i<words.size();i++)
        {
            string x=words[i];
            reverse(x.begin(),x.end());
            mp[x]=i;
        }
        vector<vector<int>> res;
        for(int j=0;j<words.size();j++)
        {
            string str=words[j];
            for(int i=0;i<=str.size();i++)
            {
                string prefix=str.substr(0,i);
                string suffix=str.substr(i);
                if(!prefix.empty() and isPalindrome(prefix) and mp.count(suffix)and j!=mp[suffix])
                {
                    res.push_back({mp[suffix],j});
                }
                if(isPalindrome(suffix) and mp.count(prefix) and j!=mp[prefix] )
                {
                    res.push_back({j,mp[prefix]});
                }
            }
        }
        return res;
    }
};
