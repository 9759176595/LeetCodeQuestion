class Solution {
public:
    long long numberOfWays(string s) {
        int n=s.size();
        long long ans=0;
        vector<int>prez(n,0),preo(n,0);
        for(int i=0;i<n;i++){
            if(i==0){
                prez[i]=s[i]=='0'?1:0;
                preo[i]=s[i]=='1'?1:0;
                continue;
            }
            prez[i]=prez[i-1]+(s[i]=='0');
            preo[i]=preo[i-1]+(s[i]=='1');
        }
        for(int i=1;i<n-1;i++){
            if(s[i]=='1'){
                long long x=prez[i-1];
                long long y=prez[n-1]-prez[i];
                ans+=(x*y);
            }
            else{
                long long x=preo[i-1];
                long long y=preo[n-1]-preo[i];
                ans+=(x*y);
            }
        }
        return ans;
    }
};
