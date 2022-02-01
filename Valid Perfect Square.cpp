class Solution {
public:
    bool isPerfectSquare(int n) {
         int ld=n%10;
        if(ld==2 || ld==3 || ld==7 || ld==8)
            return false;
        int l=1;
        int r=n;
        while(l<=r){
            long long int mid=l+(r-l)/2;
            long long int sq=mid*mid;
            if(sq==n)
                return true;
            else if(sq<n)
                l=mid+1;
            else
                r=mid-1;
        }
        return false;
    }
};
