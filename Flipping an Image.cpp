class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int c=A[0].size();
        for(auto &row: A){
            for(int i=0;i<(c+1)/2;i++){
                int temp=row[i];
                row[i]=1-row[c-1-i];
                row[c-1-i]=1-temp;
            }
        }
        return A;
    }
};
