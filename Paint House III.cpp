class Solution {
public:
 int dp[105][25][105];
    // i-> current index of house
    // prevcolor -> color of the previous house
    // currtarget -> count of neighbourhood
    int solve(int i,int prevcolor,int currtarget,int m,int n,int target,vector<int>& houses, vector<vector<int>>& cost)
    {
        if(currtarget>target)
            return 1e9;
        if(i==m)
        {
            if(currtarget==target)
                return 0;
            else
                return 1e9;
        }
        if(dp[i][prevcolor][currtarget]!=-1)
            return dp[i][prevcolor][currtarget];
        // if house is already painted
        if(houses[i]!=0)
        {
            if(houses[i]!=prevcolor) // if color of present house is not as same of the previous house then count of neighbourhood increases
                return dp[i][prevcolor][currtarget]=solve(i+1,houses[i],currtarget+1,m,n,target,houses,cost);
            else // if color of present house is same as that of the previous house then count of neighbourhood remains same
                return dp[i][prevcolor][currtarget]=solve(i+1,prevcolor,currtarget,m,n,target,houses,cost);
        }
        else // if house is not painted
        {
            int ans=1e9;
            // try for every possible color from 1 to n
            for(int j=1;j<=n;j++)
            {
                int temp;
                houses[i]=j; // assign the color of house[i] to j
                if(houses[i]!=prevcolor) // if color of present house is not as same of the previous house then count of neighbourhood increases
                    temp=cost[i][j-1]+solve(i+1,houses[i],currtarget+1,m,n,target,houses,cost);
                else // if color of present house is same as that of the previous house then count of neighbourhood remains same
                    temp=cost[i][j-1]+solve(i+1,prevcolor,currtarget,m,n,target,houses,cost);
                ans=min(ans,temp);
                houses[i]=0; //reassign the color of house[i] to 0
            }
            return dp[i][prevcolor][currtarget]=ans;
        }
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
       memset(dp,-1,sizeof(dp));
        int ans=solve(0,0,0,m,n,target,houses,cost);
        if(ans==1e9)
            return -1;
        return ans;
    }
};
