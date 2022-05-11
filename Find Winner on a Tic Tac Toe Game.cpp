class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        //Minimum moves required to decide a winner
        if(moves.size() < 5) {
            return "Pending";
        }
        //populate matrix
        vector<vector<char>> matrix(3,vector<char>(3,'.'));
        for(int i=0; i< moves.size(); ++i) {
            if(i%2 == 0) {
                matrix[moves[i][0]][moves[i][1]] = 'x';//A move
            } else {
                matrix[moves[i][0]][moves[i][1]] = 'o';//B move
            }
        }
        //check for rows and columns
        for(int i=0; i<matrix.size(); ++i) {
            if(matrix[i][0] != '.' and matrix[i][0] == matrix[i][1] and matrix[i][1] == matrix[i][2]) {
                if(matrix[i][0] == 'x')
                    return "A";
                else
                    return "B";
            }
            if(matrix[0][i] != '.' and matrix[0][i] == matrix[1][i] and matrix[1][i] == matrix[2][i]) {
                if(matrix[0][i] == 'x')
                    return "A";
                else
                    return "B";
            }
        }
        //check one diagonal
        if(matrix[0][0] != '.' and matrix[0][0] == matrix[1][1] and matrix[1][1] == matrix[2][2]) {
            if(matrix[0][0] == 'x')
                return "A";
            else
                return "B";
        }
        //check other diagonal
        if(matrix[0][2] != '.' and matrix[0][2] == matrix[1][1] and matrix[1][1] == matrix[2][0]) {
            if(matrix[0][2] == 'x')
                return "A";
            else
                return "B";
        }
        //check for Draw
        if(moves.size() == 9) {
            return "Draw";
        }
        return "Pending";
    }
};
