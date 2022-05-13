class Solution {
public:
    int trailingZeroes(int n) {
        int zeros = 0;
        int rem = 0;
        if(n < 5)
            return 0;
        while(n >= 5)
        {
            
            rem += n/5;
            n = n/5;
        }
        return rem;
    }
};
