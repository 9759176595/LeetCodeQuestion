class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(),special.end());
        int start=bottom;
        int end=top;
        int ans=0;
        for(int i=0;i<special.size();i++){
            int specialFloorIndex=special[i];
            int diff=specialFloorIndex-start;
            ans=max(ans,diff);
            start=specialFloorIndex+1;
        }
        ans=max(ans,end-special[special.size()-1]);
        return ans;
    }
};
