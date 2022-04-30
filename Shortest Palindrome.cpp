class Solution {
public:
    string shortestPalindrome(string s) {
         int n=s.size();
        string rev(s);
        reverse(rev.begin(),rev.end());
        string s_n=s+"#"+rev;
        cout<<s_n<<"\n";
        vector<int> lps(s_n.size()+1);
        int k=0;
        lps[0]=0;
        for(int i=1;i<s_n.size();){
            if(s_n[i]==s_n[k]){
                k++;
                lps[i++]=k;
            }
            else{
                if(k!=0){
                    k=lps[k-1];
                }
                else{
                    k=0;
                    i++;
                }
            }
        }
        return rev.substr(0,n-lps[s_n.size()-1])+s;
    }
};
