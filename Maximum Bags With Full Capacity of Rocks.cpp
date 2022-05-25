class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n=capacity.size();
        vector<int>vacancy(n);
        for(int i=0;i<n;i++){
            vacancy[i]=capacity[i]-rocks[i];
        }
        sort(vacancy.begin(),vacancy.end());
        int count=0;
        for(int i=0;i<n;i++){
            if(vacancy[i]==0) count++;
            else {
                if(additionalRocks>=vacancy[i]){
                    additionalRocks-=vacancy[i];
                    count++;
                }
                else break;
            }
        }
        return count;
    }
};
