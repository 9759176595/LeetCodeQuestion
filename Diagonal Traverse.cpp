class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
       int m=mat.size(),n=mat[0].size(),k=0;
        vector<vector<int>>temp(m+n);
        vector<int>ans;
		
		// convert mat into adjacency list and keep value in temp
		
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                temp[i+j].push_back(mat[i][j]);
            }
        }
		
		// here we reverse matrix
		
        for(int i=0;i<m+n;i++){
            if(i%2==0){
                reverse(temp[i].begin(),temp[i].end());
            }
        }
		
		// all value  of temp in ans vector
		
        for(int i=0;i<m+n;i++){
            for(int j=0;j<temp[i].size();j++){
                ans.push_back(temp[i][j]);
            }
         }
        return ans; 
    }
};
