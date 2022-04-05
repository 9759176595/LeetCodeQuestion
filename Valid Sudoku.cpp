class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
//        int R=board.size();
//         int C=board[0].size();
//         unordered_map<char,int>row[9];
//         unordered_map<char,int>col[9];
//         unordered_map<char,int>boxes[9];
        
//         for(int i=0;i<R;i++){
//             for(int j=0;j<C;j++){
//                 char ch=board[i][j]; //current cell
                
//                 if(ch!='.' && (row[i][ch]++>0 || col[j][ch]++> 0 ||
//                               boxes[i/3*3+j/3][ch]++ >0))
//                     return false;
//             }
//         }
//         return true;
    
        //-----------METHOD 2
        int R=board.size();
        int C=board[0].size();
        
        unordered_set<string>S;
         for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                
                if(board[i][j]=='.')
                    continue;
                string ch(1,board[i][j]);
                string row="("+to_string(i)+")"+ch;  /// (0)5
                string col=ch+ "("+ to_string(j)+ ")";  //   7(5)
                string box="(" + to_string(i/3)+ ch + to_string(j/3) +")"; // (080)
                
                if(S.find(row)!=S.end() || S.find(col)!=S.end() || S.find(box)!=S.end()){
                    return false; 
                }
                else{
                    S.insert(row);
                    S.insert(col);
                    S.insert(box);
                }
            }
        }
        return true;
    }
};
