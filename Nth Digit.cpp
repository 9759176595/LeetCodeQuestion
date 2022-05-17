class Solution {
public:
    int findNthDigit(int n) {
         // find the tier 
        long digits = 1;
        long base = 9;
                
        // tier   digits  numbers in tier
        // 1- 9      1      9 
        // 10- 99    2      90 
        // 100-999   3      900
        while(n > base * digits)
        {
            n -= base * digits;
            base*=10;
            digits++;
            
        }
        int offset = (n-1)/digits;
        int index = (n-1)% digits;
        int start = pow(10, digits -1);
        return to_string(start +offset)[index] - '0';
    }
};
