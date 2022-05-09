class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
         int n = mat.size();
        int sum=0;
        
        // adding left diagonal(i,i) and right diagonal (i,n-i-1)
        for(int i=0;i<n;i++){
            sum += mat[i][i] + mat[i][n-i-1];
        }
        
        // if n is odd, subtract centre element
        if(n%2 == 1)
            sum -= mat[n/2][n/2];
        return sum;    
    }
};
