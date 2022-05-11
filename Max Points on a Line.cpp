class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
         if(points.size() <= 2)
            return points.size();
        
        int ans = 2;
        int n = points.size();
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int cnt = 2;
                for(int k = j+1; k < n; k++) {
                    int x1 = points[i][0];
                    int y1 = points[i][1];
                    
                    int x2 = points[j][0];
                    int y2 = points[j][1];
                    
                    int x3 = points[k][0];
                    int y3 = points[k][1];
                    
                    if((y2-y1)*(x3-x2) == (x2-x1)*(y3-y2))
                        cnt += 1;
                }
                ans = max(ans, cnt);
            }
        }
        
        return ans;
    }
};
