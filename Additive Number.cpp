class Solution {
public:
    bool dfs(string &s,vector<long long>& re,int in){
	    if(re.size()>=3){
            int n = re.size()-1;
            if(re[n]!=re[n-1]+re[n-2]) return 0;
        }
        if(in>=s.size()){
            if(re.size()<3) return 0;
            return 1;
        }
        if(s[in]=='0'){
            re.push_back(0);
            if(dfs(s,re,in+1)) return 1;
            re.pop_back(); 
            return 0;
        }
        string k; long long n=0;
        for(int i = in; i<s.size() && i-in+1<=15;++i){
            k+=string(1,s[i]);
            n=n*10+s[i]-'0';
            re.push_back(n);
            if(dfs(s,re,i+1)) return 1;
            re.pop_back();
        }
        return 0;
    }
    
    bool isAdditiveNumber(string s) {
        vector<long long>re;
        return dfs(s,re,0);
    }
};
