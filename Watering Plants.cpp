class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
       int step=0;
        int c=capacity;
        for(int i=0;i<plants.size();i++){
            if(plants[i]<=c){
                c-=plants[i];
                step++;
            }
           else if(plants[i]>c){
                c=capacity;
                c-=plants[i];
                step+=(2*i+1);
            }
        }
        return step;
    }
};
