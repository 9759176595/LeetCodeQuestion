class Solution {
public:
//     If there are 1,2,3 stones left we can always win immediately, hence 1,2,3 are winning positions and 4 is a losing position.
// If there are 5, 6, or 7 stones, we can take 1, 2, or 3 respectively to put our friend into a losing position.
// Continuing this logic we see that every position with a multiple of 4 stones is a losing position and all others are winning positions.
    bool canWinNim(int n) {
       return n % 4 != 0;
    }
};
