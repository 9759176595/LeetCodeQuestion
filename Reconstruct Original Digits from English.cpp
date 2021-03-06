class Solution {
public:
    string originalDigits(string s) {
         string result;
        std::unordered_map<char, int> charFreqMap;
        for (const auto c : s) {
            ++charFreqMap[c];
        }
        vector<int> digit(10, 0);
        digit[0] = charFreqMap['z']; // unique z
        digit[2] = charFreqMap['w']; // unique w
        digit[4] = charFreqMap['u']; // unique u
        digit[6] = charFreqMap['x']; // unique x
        digit[8] = charFreqMap['g']; // unique g
        
        digit[3] = charFreqMap['h'] - digit[8]; // h present in three and eight
        digit[5] = charFreqMap['f'] - digit[4]; // f present in five and four
        digit[7] = charFreqMap['s'] - digit[6]; // s present in seven and six
        
        digit[9] = charFreqMap['i'] - digit[5] - digit[6] - digit[8];
        digit[1] = charFreqMap['n'] - digit[7] - 2 * digit[9];
        
        char num = '0';
        for (const auto count : digit) {
            result.append(count, num++);
        }
        return result;
    }
};
