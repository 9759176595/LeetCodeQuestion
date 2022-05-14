class Solution {
public:
    string getHint(string secret, string guess) {
       int n = secret.length();
        int A=0, B=0;
        
        int freq[2][10]={0};
        
        for(int i=0;i<n;i++) 
        {
            if(secret[i]==guess[i]) A++;
            else 
            {
                freq[0][secret[i]-'0']++;
                freq[1][guess[i]-'0']++;
            }
        }
        for(int i=0;i<10;i++) B+=min(freq[0][i],freq[1][i]);
        return to_string(A)+"A"+to_string(B)+"B";
    }
};
