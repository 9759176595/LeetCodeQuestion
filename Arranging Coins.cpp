class Solution {
public:
    int arrangeCoins(int n) {
        long long int m=n;
        long long int t=2*m;
        long long int res=sqrt(1+4*t)-1;
        return res/2;
    }
};
