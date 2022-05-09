class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>&v, int m, int n) {
        if(v.size()!=m*n) return {};
		vector<vector<int>> ans(m,vector<int>(n));
		for(int i=0,j=0,k=0; i<v.size(); i++,j++){
			if(j==n){
				k++;
				j=0;
			}
			ans[k][j] = v[i];
		}
		return ans;
    }
};
