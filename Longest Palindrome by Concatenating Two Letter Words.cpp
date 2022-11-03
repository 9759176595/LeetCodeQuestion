// The maximum possible number of times such a word occurs in the palindrome is the minimum number of times this word and its reverse occur in the input (e.g., when there are 7 ab's and 4 ba's, we can only use 4 occurrences of ab and ba in the final string).
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int>count;
        for(const string & word : words){
            count[word]++;
        }
        int ans=0;
        bool central=false;
        for(const auto& [word, countOfTheWord]: count){
            //if word is a palindrome
            if(word[0]==word[1]){
                if(countOfTheWord %2==0){
                    ans+=countOfTheWord;
                }
                else{
                    ans+=countOfTheWord-1;
                    central=true;
                }
                // consider a pair of non-palindrome words such that one is the
                // reverse of another ({word[1], word[0]} is the reversed word)
            }
            else if(word[0] < word[1] && count.count({word[1], word[0]})){
                ans+=2*min(countOfTheWord, count[{word[1], word[0]}]);
            }
        }
        if(central) ans++;
        return 2*ans;
    }
};
