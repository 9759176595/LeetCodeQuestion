class Solution {
public:
    map<int,int>visited;
    int ans=0;
    int c=0;
    void dfs(vector<int>&v,int i)
    {
        c++;
        visited[i]=1;
        int item=v[i];
        if(visited[item]==0)
        {
            dfs(v,item);
        }
        ans=max(ans,c);
    }
    int arrayNesting(vector<int>& nums) {
          for(int i=0;i<nums.size();i++)
        {
            c=0;
            if(visited[i]==0)
                dfs(nums,i);
        }
        return ans;
    }
};
// Time complexity : O(n)O(n). Every element of the numsnums array will be considered atmost once.

// Space complexity : O(n)O(n). visitedvisited array of size nn is used.

