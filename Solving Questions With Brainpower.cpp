class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        //long dp[]=new long[questions.size()];
        long dp[n];
        for(int i=questions.size()-1;i>=0;i--){
            int futureReachIndx=i+questions[i][1]+1;
            if(futureReachIndx<questions.size())
                dp[i]=dp[futureReachIndx]+questions[i][0];
            else
                dp[i]=questions[i][0];
            if(i<questions.size()-1){
                dp[i]=max(dp[i+1],dp[i]);
            }
        }
        return dp[0];
    }
};
