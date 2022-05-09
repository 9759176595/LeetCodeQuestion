class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
       int n = matrix.size();
        //Mark rows
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int posToMark = abs(matrix[i][j])-1; 
                if(matrix[i][posToMark] < 0) return false;

                matrix[i][posToMark] = -matrix[i][posToMark];
            }
        }
        
        //Mark cols
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int posToMark = abs(matrix[j][i]) - 1;
                if(matrix[posToMark][i] > 0) return false;

                matrix[posToMark][i] = abs(matrix[posToMark][i]);
            }
        }
        return true; 
    }
};
