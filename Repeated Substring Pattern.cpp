class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.length();
        vector<int> raj(n,0);
        for(int i=1;i<n;i++){
            int j=raj[i-1];
            while(j>0 && s[i]!=s[j])
                j=raj[j-1];
            if(s[i]==s[j])
                ++j;
            raj[i]=j;
        }
        int l=raj[n-1];
        return (l!=0)&&(l%(n-l)==0);
    }
};
