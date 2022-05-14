class Solution {
public:
    int hIndex(vector<int>& citations) {
       int n=citations.size();
        int l=0,r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(citations[mid]<n-mid)
                l=mid+1;
            else
                r=mid-1;
        }
        return n-l;
        
        //M2
        // int i=n-1;
        // while(i>=0){
        //     if(citations[i]<n-i) break;
        //     i--;
        // }
        // return n-i-1;
    }
};
