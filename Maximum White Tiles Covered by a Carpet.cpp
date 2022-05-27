class Solution {
public:
     // Time Complexity:- O(NlogN)
    // Space Complexity:- O(N)
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        int ans = 0,n = tiles.size();
 
        sort(tiles.begin(),tiles.end());
 
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            arr[i] = tiles[i][1] - tiles[i][0] + 1;
            if(i>0){
                arr[i] += arr[i-1];
            }
        }
 
        for(int i=0;i<n;i++){
            int leftEnd = tiles[i][0],rightEnd = tiles[i][0] + carpetLen - 1;
 
            int l = i,r = n - 1,left = i,right = i - 1;
            while(l<=r){
                int mid = (l+r)/2;
                if(tiles[mid][1]<=rightEnd){
                    right = mid;
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
 
            int curr = 0;
 
            if(right!=i-1){
                curr += arr[right];
                if(left>0){
                    curr -= arr[left-1];
                }
            }
 
            if(right+1<n){
                curr += max(0,rightEnd-tiles[right+1][0]+1);
            }
 
            ans = max(ans,curr);
        }
 
        return ans;
    }
};
