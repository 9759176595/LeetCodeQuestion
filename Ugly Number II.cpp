class Solution {
public:
    int nthUglyNumber(int n) {
         vector<int>ans(n);
    ans[0]=1; //1 will always be there
    int two=0,three=0,five=0; //these are the pointer to keep a track
    for(int i=1;i<n;++i){
        int multwo = ans[two]*2;
        int multhree = ans[three]*3;
        int mulfive = ans[five]*5;
        ans[i] = min(multwo,min(multhree,mulfive)); //taking minimum of all the three above
		// incrementing the pointer whose value was found minimum
        if(ans[i]==multwo) two++;
        if(ans[i]==multhree) three++;
        if(ans[i]==mulfive) five++;
    }
    return ans[n-1];
    }
};
