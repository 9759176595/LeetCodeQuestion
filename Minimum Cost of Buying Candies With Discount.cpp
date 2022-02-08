class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int n=cost.size();
        
        int price=0;
        int i=n-1;
        while(i>1){
            
            /// 2 candy add kro 3 wale ko skip kro end se
            // 3rd wala free me mil jayege
            price+=cost[i--];
            price+=cost[i--];
            i--;
        }
        while(i>=0){
            price+=cost[i--];
        }
        return price;
    }
};
