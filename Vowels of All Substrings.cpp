class Solution {
public:
    long long countVowels(string word) {
        long long int a = 0,b = 0;
        int n = word.length();
        for(int i = 0; i < n; i++){
            
            auto x = word[i];
            
            a = a + b;
            
            b = b + ((x=='a' || x=='e' || x=='i' || x=='o' || x=='u') ? (i+1) : 0);
            
        }
        
        return a + b;
    }
};
