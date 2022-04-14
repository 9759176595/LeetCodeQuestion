class Solution {
public:
    vector<int> parent;
    int count;
    
    int _find(int x)
    {
        if (parent[x] == x)
            return x;
        
        int temp = _find(parent[x]);
        parent[x] = temp;
        return temp;
    }
    
    void _union(int x, int y)
    {
        int px = _find(x), py = _find(y);
        if (px != py)
        {
            parent[py] = px;
        }
        else
            count++;
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int dot = n+1;
        
        for (int i=0; i<(dot*dot); i++)
        {
            parent.push_back(i);
        }
        
        for (int i=0; i<dot; i++)
        {
            for (int j=0; j<dot; j++)
            {
                if (i==0 || j==0 || i == dot-1 || j==dot-1)
                {
                    int cellno = i*dot + j;
                    _union(0, cellno);
                }
            }
        }
        
        for (int i=0; i<grid.size(); i++)
        {
            for (int j=0; j<grid[i].size(); j++)
            {
                if(grid[i][j] == '/')
                {
                    int cell1 = i*dot + (j+1);
                    int cell2 = (i+1)*dot + j;
                    _union(cell1, cell2);
                }
                else if (grid[i][j] == '\\')
                {
                    int cell1 = i*dot + j;
                    int cell2 = (i+1)*dot + (j+1);
                    _union(cell1, cell2);
                }
            }
        }
        return count;
    }
};
