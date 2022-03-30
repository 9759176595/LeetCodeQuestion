class Solution {
public:
    vector<vector<int>>dp;
    bool solve(string a,string b, string c,int i, int j, int k){
        int na=a.size();
        int nb=b.size();
        int nc=c.size();
        
        if(k==nc && i==na && j==nb){
            return true;
        }
        else if(k==nc){
            return false;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        bool res=false;
        if(i<na && a[i]==c[k])
        {
            res=res||solve(a,b,c,i+1,j,k+1);
        }
        if(j<nb && b[j]==c[k])
        {
            res=res||solve(a,b,c,i,j+1,k+1);
        }
      return dp[i][j]=res;
    }
    bool isInterleave(string a, string b, string c) {
         int na=a.size();
        int nb=b.size();
        int nc=c.size();
        
        dp.assign(na+1,vector<int>(nb+1,-1));
        return solve(a,b,c,0,0,0);
        
    }
};
