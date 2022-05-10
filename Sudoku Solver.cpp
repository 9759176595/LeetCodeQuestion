class Solution {
public:
    bool check(vector<vector<char>>&b,int r,int c,char num)
    {
        // row condition
        for(int i=0;i<9;i++) // complete row bcz some numbers are already present
            if(b[i][c]==num)
                return false;
        // column
        for(int i=0;i<9;i++)
            if(b[r][i]==num)
                return false;
        // sub-grid
       r=3*(r/3);
        c=3*(c/3);
        for(int i = 0;i<3;i++)
            for(int j=0;j<3;j++)
            {
                if(b[i+r][j+c]==num)
                    return false;
            }
        
        return true;
    }
    
    bool solve(vector<vector<char>>&b,int r,int c)
    { 
        if(r==9)
        return true;
        
        if(c==9)
         return  solve(b,r+1,0);
            
         if(b[r][c]!='.')
         return solve(b,r,c+1);

        for(char num ='1';num<='9';num++)
            {  
                if(check(b,r,c,num))
                {
                    b[r][c]=num;                    
                    if(solve(b,r,c+1)) // return if solution found, no need to check other cases 
                        return true;
                    b[r][c]='.';
                }
            }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
         solve(board,0,0);
    }
};
