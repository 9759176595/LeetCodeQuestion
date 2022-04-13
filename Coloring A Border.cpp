class Solution {
public:
    void dfs(vector<vector<int>>& g, int x, int y, int p, int c){
        if(g[x][y] != p){
            return;
        }
        g[x][y] = -1*p;
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        int count = 0;
        for(int i=0;i<4;i++){
            int xdir = x+dir[i].first;
            int ydir = y+dir[i].second;
            // cout<<x<<" "<<y<<": "<<xdir<<" "<<ydir<<endl;
            if(xdir<0||ydir<0||xdir>=g.size()||ydir>=g[0].size()){
                count++;
                continue;
            }
            else if(abs(g[xdir][ydir]) != p){
                count++;
            }
            dfs(g, xdir, ydir, p, c);
        }
        // cout<<x<<" "<<y<<": "<<count<<endl;
        if(count==0){
            g[x][y] = p;
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        dfs(grid, row, col, grid[row][col], color);
        for(auto &i: grid){
            for(auto &j: i)
                if(j<0){
                    j=color;
                }
        }
        return grid;
    }
    
};
