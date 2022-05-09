class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
          //Size of the row and column
        int m=matrix.size(),n=matrix[0].size();
		
		//Creating vectors to store min of every row and max of every column
        vector<int> mx(n,0);
        vector<int> mn(m,0);
		
		//Vector to finally return all lucky numbers
        vector<int> ans;
        
		//Traversing to get max of every column
        for(int i=0;i<n;i++){
            int j=0;
            int mx1=INT_MIN;
            while(j!=m){
              mx1=max(mx1,matrix[j][i]);
              if(j==m-1){
                mx[i]=mx1;
              }
              j++;
            }
        }

        //Traversing to get min of every row
        for(int i=0;i<m;i++){
            int j=0;
            int mn1=INT_MAX;
            while(j!=n){
              mn1=min(mn1,matrix[i][j]);
              if(j==n-1){
                mn[i]=mn1;
              }
              j++;
            }
        }
        
		//Traversing both the mx,mn to check all the same elements and adding in ans vector.
        for(int i=0;i<mx.size();i++){
           for(int j=0;j<mn.size();j++){
               if(mx[i]==mn[j]){
                   ans.push_back(mx[i]);
               }
           }
        }
        return ans;
    }
};
