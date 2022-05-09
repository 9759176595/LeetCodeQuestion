class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
         for(int i=0;i<matrix[0].size()-1;i++)
        {
            int row=0;
            int col=i;
            while(row<matrix.size() && col<matrix[0].size())
            {
                if(matrix[0][i]!=matrix[row][col])
                    return 0;
                row++;
                col++;
            }
        }
        
        for(int i=1;i<matrix.size()-1;i++)
        {
            int row=i;
            int col=0;
            while(row<matrix.size() && col<matrix[0].size())
            {
                if(matrix[i][0]!=matrix[row][col])
                    return 0;
                row++;
                col++;
            }
        }
        return 1;
    }
};
