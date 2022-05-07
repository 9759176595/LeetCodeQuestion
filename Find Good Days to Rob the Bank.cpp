class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& sec, int time) {
        int n=sec.size();
        vector<int>leftInc(n,0),rightInc(n,0);
        int cnt=0;
        for(int i=1;i<n-1;i++){
            if(sec[i]<=sec[i-1]){
                cnt++;
                leftInc[i]=cnt;
            }
            else cnt=0;
        }
        cnt=0;
        for(int i=n-2;i>=0;i--){
            if(sec[i]<=sec[i+1]){
                cnt++;
                rightInc[i]=cnt;
            }
            else cnt=0;
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(leftInc[i]>=time && rightInc[i]>=time)
                ans.push_back(i);
        }
        return ans;
    }
};
