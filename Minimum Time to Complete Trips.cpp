class Solution {
public:
    long long tripstaken(vector<int>&time, long long period){
        long long cnt=0;
        for(auto t: time){
            cnt+=period/t;
        }
        return cnt;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low=0,high=1e14, mid;
        long long ans=0;
        while(low<=high){
            mid=low+(high-low)/2;
            if(tripstaken(time,mid)>=totalTrips)
                ans=mid,high=mid-1;
            else
                low=mid+1;
        }
        return ans;
    }
};









