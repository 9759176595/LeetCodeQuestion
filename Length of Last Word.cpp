class Solution {
public:
    int lengthOfLastWord(string s) {
        //-----METHOD 1------
        // stringstream ss(s);
        // string word;
        // while(ss >> word){}
        // return word.length();
        
        //---------------
        
        int n=s.length(), res=0;
        while(n>0){
            if(s[--n]!=' ')
                res++;
            else if(res>0)
               return res;
        }
        return res;
    }
};
