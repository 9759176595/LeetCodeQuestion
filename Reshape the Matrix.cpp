class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        //------------METHOD 1
        // int rows=mat.size();
        // int cols=mat[0].size();
        // if(rows*cols<r*c || rows*cols>r*c){
        //     return mat;
        // }
        // vector<int>me;
        // for(int i=0;i<rows;i++){
        //     for(int j=0;i<cols;j++){
        //         me.push_back(mat[i][j]);
        //     }
        // }
        // int k=0;
        // vector<vector<int>>new_mat(r,vector<int>(c,0));
        // for(int i=0;i<r;i++){
        //     for(int j=0;j<c;j++){
        //         new_mat[i][j]=me[k];
        //         k++;
        //     }
        // }
        // return new_mat;
        
        //=========METHOD 2
        int m=mat.size(), n=mat[0].size(), o =m*n;
        if(r*c!=o)
            return mat;
        vector<vector<int>>res(r,vector<int>(c,0));
        for(int i=0;i<o;i++)
            res[i/c][i%c]=mat[i/n][i%n];
        return res;
    }
};
