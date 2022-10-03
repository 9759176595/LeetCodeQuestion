class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
         int cur = -1 , mx = 0 , cnt = 0 , tot = 1e9;
        int n = colors.size();
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(cur != colors[i]){
                ans += (cnt > 1) * (tot - mx);
                cur = colors[i];
                tot  = neededTime[i];
                mx = neededTime[i];
                cnt = 1;
            }else{
                cnt++;
                mx = max(mx , neededTime[i]);
                tot += neededTime[i];
            }
        }
        ans += (cnt > 1) * (tot - mx);
        return ans;
    }
};
