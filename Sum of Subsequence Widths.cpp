class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        int n=A.size();
        long mod=1000000007;
        sort(A.begin(),A.end());
        vector<long>pow2(n);
        pow2[0]=1;
        for(int i=1;i<n;i++){
            pow2[i]=(pow2[i-1]*2)%mod;
        }
        long ans=0;
        for(int i=0;i<n;i++){
            ans=(ans+(pow2[i]-pow2[n-i-1])*A[i])%mod;
        }
        return (int)ans;
    }
};
