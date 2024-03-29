class Solution {
public:
    int digit(int x){
        int count=0;
        while(x){
            count++;
            x=x/10;
        }
        return count;
    }
    void findNumbers(int cur_digit,int n, int k, vector<int>&result){
        //base case
        if(digit(cur_digit)==n){
            result.push_back(cur_digit);
            return;
        }
        for(int i=0;i<10;i++){
            int last_digit=cur_digit%10;
            if(abs(last_digit-i)==k){
                findNumbers((cur_digit*10+i),n,k,result);
            }
        }
        
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>res;
        for(int i=1;i<10;i++){
            findNumbers(i,n,k,res);
        }
        return res;
    }
};
