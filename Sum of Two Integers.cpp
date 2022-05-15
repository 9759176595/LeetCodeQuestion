class Solution {
public:
    int getSum(int a, int b) {
          unsigned int d = (unsigned int)(b); // define an unsigned version of b for shifting purposes (since we're bit manipulating, the signs don't matter)
	int c = 0; // c will store the previous sum value
    while (d != 0) { // while we no longer have to carry, iterate
		c = a; // store the previous sum value in c
        a = a ^ d; // perform the addition without carry
        d = c & d; // determine places that resulted in carry out
        d = d << 1; // turn carry out into carry in with 1 left shift
    }
    return a; // a stores our sum, return it
    }
};
