class Solution {
public:
    int trap(vector<int>& height) {
        int s=height.size();
        int mxl[s];
        int mxr[s];
        mxl[0]=height[0];
        for(int i=1;i<s;i++){
            mxl[i]=max(mxl[i-1],height[i]);
        }
        mxr[s-1]=height[s-1];
        for(int i=s-2;i>=0;i--){
            mxr[i]=max(mxr[i+1],height[i]);
        }
        int water[s];
        for(int i=0;i<s;i++){
            water[i]=min(mxl[i],mxr[i])-height[i];
        }
        int sum=0;
        for(int i=0;i<s;i++){
            sum=sum+water[i];
        }
        return sum;
    }
};
