class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
      // int A[n][n];
        vector<vector<int> > A( n, vector<int>(n) );
        int top=0, bottom=n-1,left=0,right=n-1;
        int val=1;
        while(val<=n*n){
            for(int i=left;i<=right;i++){
                A[top][i]=val++;
            }
            top++;
            for(int i=top;i<=bottom;i++)
                A[i][right]=val++;
            right--;
            //bottomost row
            for(int i=right;i>=left;i--)
                A[bottom][i]=val++;
            bottom--;
            //for left column
            for(int i=bottom;i>=top;i--)
                A[i][left]=val++;
            left++;
        }
        return A;
    }
};
