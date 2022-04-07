class Solution {
public:
    int flipLights(int n, int p) {
       if (p == 0) return 1; // no presses, original state
        if (n == 1) return 2; // constraint: (p > 0) : one light, binary states.
        if (p == 1) return n > 2 ? 4 : 3; // constraint: (p > 0 && n > 1) : one press, if (1) two lights -> all 2^2 but original state = 3 states (2) more than two lights -> 011, 010, 101, 000 = 4 states
        if (n == 2) return 4; // constraint: (p > 1 && n > 1) : two lights, multiple press, 4 states.
        return p == 2 ? 7 : 8; // constraint: (p > 1 && n > 2) : if only two presses, can't be in 4(011) state -> 8-1 = 7
    }
};




