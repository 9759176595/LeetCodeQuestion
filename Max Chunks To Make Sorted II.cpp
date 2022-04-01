class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        vector<int>rmin(n+1,0);
        int lmax=-(int)1e9;
        rmin[n]=(int)1e9;
        int val=(int)1e9;
        for(int i=n-1;i>=0;i--){
            val=min(val,arr[i]);
            rmin[i]=val;
        }
        int chunks=0;
        for(int i=0;i<n;i++){
            lmax=max(lmax,arr[i]);

            if(lmax<=rmin[i+1]){
                chunks++;
            }
        }
        return chunks;
    }
};
