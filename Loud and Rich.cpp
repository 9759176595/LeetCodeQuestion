class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<int>res(n,-1);
        //create a adjacency list
        vector<vector<int>>adj(n);
        for(int i=0;i<richer.size();i++){
            adj[richer[i][1]].push_back(richer[i][0]);
            
        }
        for(int i=0;i<n;i++){
            if(res[i]==-1){
                dfs(i,adj,res,quiet);
            }
        }
        return res;
    }
    int dfs(int person,vector<vector<int>>&adj,vector<int>&res,vector<int>&quiet){
        int minPerson=person;
        for(auto rich:adj[person]){
            if(res[rich]!=-1){
                if(quiet[res[rich]]<quiet[minPerson]){
                    minPerson=res[rich];
                }
            }
            else{
                int somePerson=dfs(rich,adj,res,quiet);
                if(quiet[somePerson]<quiet[minPerson]){
                    minPerson=somePerson;
                }
            }
        }
        res[person]=minPerson;
        return minPerson;
    }
};
