class Solution {
public:
    int minSteps(string s, string t) {
          vector<int> counts_s(26, 0); //count the number of times each char appears in s
        vector<int> counts_t(26, 0); //count the number of times each char appears in t
        for(int i = 0; i < s.size(); i++) counts_s[s[i]-'a']++;
        for(int i = 0; i < t.size(); i++) counts_t[t[i]-'a']++;
        int steps = 0;
        for(int i = 0; i < 26; i++)
            steps += abs(counts_s[i] - counts_t[i]); //add steps needed to equalize counts of each letter
        return steps;
    }
};
