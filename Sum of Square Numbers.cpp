class Solution {
public:
    bool judgeSquareSum(int c) {
       long long int left=0;
       long long int right=sqrt(c);
        while(left<=right){
            long long int total=left*left+right*right;
            if(total==c)
                return true;
            else if(total<c)
                left++;
            else
                right--;
        }
        return false;
    }
};
