/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
   
public:
    int guessNumber(int n) {
        int en=n;
        int st=1;
        while(st<=en){
            int mid=st+(en-st)/2;
            if(guess(mid)==0)
                return mid;
            else if(guess(mid)==-1)
                en=mid-1;
            else
                st=mid+1;
        }
        return -1;
    }
};
