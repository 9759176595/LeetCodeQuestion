class Solution {
public:
    int magicalString(int n) {
       if(n<=0)
            return 0; // has 0 1's 
        if(n<=3)
            return 1; // has one 1's 
        int count =0; 
        vector<int> _string;
        _string.push_back(1);
        _string.push_back(2);
        _string.push_back(2);
        int idx = 2;   // the last digit index , decides how many digits will be added to the end of the string  
        int digit = 1; // present digit index, marks the present digit , either '1' or '2'
        // for the starting string the _string[idx(2)] = 2 and _string[digit(1)] = 2
        // this means that the number of elements to be inserted is 2 (idx) and the next value to be inserted is 1 (digit) 
        //digit will always be the opposite of the last character found , if the last group 
        // was of 2's digit would be 1 , if last group was of 1's digit would be 2
        while(_string.size()<n){
            if(_string[idx]==1){
                _string.push_back(digit);
            }
            if(_string[idx]==2){
                _string.push_back(digit);
                _string.push_back(digit);
            }
            if(digit==1) digit = 2;
            else digit =1;
            idx++;
        }
        for(int x = 0; x<n; x++){
            if(_string[x]==1)
                count++;    // Counting only till the n specified in the question
        }
        return count; 
    }
};
