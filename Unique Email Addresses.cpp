class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int n=emails.size();
        set<string> s;
        for(int i=0;i<n;i++){
            string back="";
            while(emails[i].back()!='@'){
                back=(char)(emails[i].back())+back;
                emails[i].pop_back();
            }
            emails[i].pop_back();
            string start="";
            for(int j=0;j<(int)emails[i].size();j++){
                if(emails[i][j]=='+')
                    break;
                else if(emails[i][j]=='.')
                    continue;
                else
                    start+=(char)(emails[i][j]);
            }
            string actual_email=start+(char)('@')+back;
            s.insert(actual_email);
        }
        return (int)s.size();
    }
};
