class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& arr, int left, int right) {
        int si=0;
        int ei=0;
        int prevc=0;
        int ans=0;
        int n=arr.size();
        while(ei<n){
            if(arr[ei]>=left && arr[ei]<=right){
                prevc=ei-si+1;
                ans+=prevc;
            }else if(arr[ei]<left){
                ans+=prevc;
            }
            else{
                prevc=0;
                si=ei+1;
            }
            ei++;
        }
        return ans;
    }
};
