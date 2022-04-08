class Solution {
public:
  static int countNegativeHelper(const vector<int>&vec){
       int l=0;
        int h=vec.size()-1;
      while(l<=h){
          int mid=l+(h-l)/2;
          if(vec[mid]>=0)
              l=mid+1;
          else
              h=mid-1;
      }
      return vec.size()-h-1;
    }
    int countNegatives(vector<vector<int>>& grid) {
        // int count=0;
        // int n=grid.size();
        // int m=grid[0].size();
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(grid[i][j]<0){
        //             count++;
        //         }
        //     }
        // }
        // return count;
        
        //--------M2
        int count=0;
        for(int i=0;i<grid.size();i++){
            count+=countNegativeHelper(grid[i]);
        }
        return count;
    }
};
