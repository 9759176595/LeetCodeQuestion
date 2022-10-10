class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n=palindrome.size();
        bool allA=true;
        for(int i=0;i<n;i++){
            if(i==n/2) continue;
            if(palindrome[i]!='a'){
                palindrome[i]='a';
                allA=false;
                break;
            }
        }
        if(allA){
            palindrome[n-1]='b';
        }
        if(n==1) return "";
        return palindrome;
    }
};
