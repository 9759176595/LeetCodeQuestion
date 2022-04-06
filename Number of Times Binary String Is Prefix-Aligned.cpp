class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        long long int tot=0;
        long long int sum=0;
        int n=flips.size();
        int ans=0;
        for(int i=0;i<n;i++){
            sum+=(i+1);
            tot+=flips[i];
            if(sum==tot)
                ans++;
        }
        return ans;
    }
};
