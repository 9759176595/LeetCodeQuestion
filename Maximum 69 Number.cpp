class Solution {
public:
    int maximum69Number (int num) {
       string s=to_string(num);
        string ans="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='6')
            {
                ans+='9';
                if(i+1<s.length())
                ans=ans+s.substr(i+1);
                break;
            }
            else
                ans+=s[i];
        }
        return stoi(ans);  
    }
};
