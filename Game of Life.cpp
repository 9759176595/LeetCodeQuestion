class Solution {
    bool isSafe(int x,int y, int r, int c){
        return (x>=0 && x<r && y>=0 && y<c);
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int r=board.size();
        int c=board[0].size();
        
        int copyBoard[r][c];
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                copyBoard[i][j]=board[i][j];
            }
        }   
        //direction array
        int dx[]={1,1,0,-1,-1,-1,0,1};
        int dy[]={0,1,1,1,0,-1,-1,-1};
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int liveCounts=0;
                for(int k=0;k<8;k++){
                    if(isSafe(i+dx[k],j+dy[k],r,c)&& copyBoard[i+dx[k]][j+dy[k]]==1)
                        liveCounts++;
                }
                 if(copyBoard[i][j]==0 && liveCounts==3)
                     board[i][j]=1;
                if(copyBoard[i][j]==1 && (liveCounts<2 || liveCounts>3))
                    board[i][j]=0;
            }
        }
    }
};
