class Solution {
public:
    void swap(string &s, int left, int right){
        char temp=s.at(left);
        s.at(left)=s.at(right);
        s.at(right)=temp;
       
    }
    bool isVowel(string &s, int indx){
        if(s.at(indx)=='a' ||s.at(indx)=='e' ||s.at(indx)=='i' ||s.at(indx)=='o' ||s.at(indx)=='u' ||
          s.at(indx)=='A' ||s.at(indx)=='E' ||s.at(indx)=='I' ||s.at(indx)=='O' ||s.at(indx)=='U')
            return true;
        return false;
    }
    string reverseVowels(string &s) {
        int left=0;
        int right=s.size()-1;
        while(left<right){
            while(left<right && isVowel(s,left)==false){
                left++;
            }
            while(left<right && isVowel(s,right)==false){
                right--;
            }
            swap(s,left,right);
            left++;
            right--;
        }
        return s;
    }
};
