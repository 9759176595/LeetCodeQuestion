class Solution {
    int solve(int n, int k){
        if(n==1 && n==k){
            return 0;
        }
        int mid=pow(2,n-1)/2;
        if(k<=mid){
            return solve(n-1,k);
        }else{
            return !solve(n-1,k-mid);
        }
    }
public:
    int kthGrammar(int n, int k) {
      return solve(n,k);
    }
};
