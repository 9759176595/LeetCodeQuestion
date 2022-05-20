// Firstly, sort all the string according to their length, if the lengths are equal sort alphabetically. Maintain count of each string. Our solution, will be from one of the strings as the longest uncommon substring could only a string which is not a subsequence of any string. So, for each unique string, check with other strings whether the string is subsequence or not. If it's not we will return the length of this string as our result. Otherwise, we will return -1 as no result was found.
class Solution {
     static int cmp(string a, string b)
    {
        if(a.length()>b.length())
            return 1;
        else if(a.length()==b.length())
            return a>b;
        else
            return 0;
    }
    int isSubSequence(string a, string b)
    {
        int m = a.length();
        int n = b.length();
        int j = 0;
        for (int i=0; i<n&&j<m; i++)
           if (a[j] == b[i])
             j++;
        return (j==m);
    }
public:
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), cmp);
        map<string, int> stringCount;
        vector<string> temp;
        
        for(int i = 0;i<strs.size();i++)    
            stringCount[strs[i]]++;
        
        
        for(int i = 0;i<strs.size();i++)
            if(stringCount[strs[i]]==1)
            {
                string a = strs[i];
                int j = 0;
                for(;j<i;j++)
                {
                    string b = strs[j];
                    if (isSubSequence(a,b) ) 
                        break;
                }
                 
                if(j==i)
                    return a.length();
            }
        return -1;
    }
};
