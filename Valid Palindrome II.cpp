class Solution {
public:
    bool validPalindrome(string s) {
        int start=0;
        int end=s.size()-1;
        int c1=0;
        
        //iterate over the string and increase start && end is decreased
        int count1=0;
        while(start<end){
            //means we are getting palindrome
            if(s[start]==s[end]){
                start++;
                end--;
            }
            else{
                count1++;//no difference where palindrome not found
                start++;  //skip1
                
            }
        }
        
        //update the start and end
        start =0;
        end=s.size()-1;
        int count2=0;
         while(start<end){
            //means we are getting palindrome
            if(s[start]==s[end]){
                start++;
                end--;
            }
            else{
                count2++;//no difference where palindrome not found
                end--;  //skip1
                
            }
        }
        if(count1==1 || count2==1) return true; //delete atmost one character
        if(count1==0 || count2==0) return true;  //already palindrom
        
        return false;
    }
};
