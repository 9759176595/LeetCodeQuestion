class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int x=edges[0][0];
        int y=edges[0][1];
        if(edges[1][0]==x || edges[1][1]==x){
            return x;
        }
        return y;
        //----------METHOD2
//         int n=0;
//         for(int i=0;i<edges.size();i++){
//             n=max(n,max(edges[i][0],edges[i][1]));
//         }
//         vector<int>indegree(n+1);
//         for(int i=0;i<edges.size();i++){
//             indegree[edges[i][0]]++;
//             indegree[edges[i][1]]++;
            
//         }
//         int res=0;
//         for(int i=0;i<indegree.size();i++){
//             if(indegree[i]==n-1){
//                 res=i;
//                 break;
//             }
//         }
//                   return res;
    }
};
