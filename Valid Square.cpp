class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        //calculating distances between vertices
        //If it is a square, then the distance between two vertices can take only 2 values
        //Either they can be at adjacent sides or at diagonals
        vector<vector<int>> points = {p1, p2, p3, p4};
        set<int> distances;
        
        for(int i = 0; i<4; ++i){
            for(int j = i+1; j<4; ++j){
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                if(x1 == x2 && y1 == y2){return false;}
                
                //Using the distance formula to calculate distance
                //Not taking square root, to avoid potential problems because of precisions.
                distances.insert(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
            }
        }
        
        //This line says if size of distance is greater than 2 return false otherwise return true.
        return distances.size() > 2 ? false : true;
    }
};
