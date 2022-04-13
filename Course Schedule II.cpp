class Solution {
    //Graph coloring 
    bool detectCycle_util(vector<vector<int>>&adj,vector<int>&visited, int v){
        if(visited[v]==1)
            return true;
        if(visited[v]==2)
            return false;
        
        visited[v]=1; // mark curr as visited
        for(int i=0;i<adj[v].size();i++){
            if(detectCycle_util(adj,visited,adj[v][i]))
                return true;
        }
        visited[v]=2;  // mark curr node as processed
        return false;
    }
    //Cycle detection
    bool detectCycle(vector<vector<int>>&adj,int n){
        vector<int>visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i])
                if(detectCycle_util(adj,visited,i))
                    return true;
        }
        return false;
    }
    //TOPO SORT
    void dfs(vector<vector<int>>&adj,int v,vector<bool>&visited,stack<int>&mystack){
        visited[v]=true;
        for(int i=0;i<adj[v].size();i++){
            if(!visited[adj[v][i]])
                dfs(adj,adj[v][i],visited,mystack);
        }
        mystack.push(v);
    }
public:
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        vector<vector<int>>adj(numCourses);
        //Make adjacency list
        for(int i=0;i<n;i++)
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
                
        //Detect cycle
            vector<int>ans;
            if(detectCycle(adj,numCourses))
                return ans;
                
        //find toposort
        stack<int>myStack;
        vector<bool>visited(numCourses,false);
        
        //Apply DFS and find topo
        for(int i=0;i<numCourses;i++){
            if(!visited[i])
                dfs(adj,i,visited,myStack);
        }
        while(!myStack.empty()){
            ans.push_back(myStack.top());
            myStack.pop();
        }
        return ans;
    }
};
