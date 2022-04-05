class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int>res={-100000,100000};
        int k=nums.size();
        int maxVal=INT_MIN;
        priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>>pq;
        
        for(int i=0;i<k;i++){
            //mol minimum of list
            int mol=nums[i][0];
            vector<int>tba{mol,0,i};
            //toa to be added
            
            //0th minimum element of vector
            //1st index of the element from my vector
            //2nd index of vector in nums
            
            maxVal=max(maxVal, mol);
            pq.push(tba);
        }
        while(true){
            vector<int>minVal=pq.top();
            pq.pop();
            if(res[1]-res[0]>maxVal-minVal[0]){
                res[0]=minVal[0];
                res[1]=maxVal;
            }
            minVal[1]++;
            vector<int>cl=nums[minVal[2]];
            if(minVal[1]==cl.size()){
                break;
            }else{
                minVal[0]=cl[minVal[1]];
                maxVal=max(maxVal,cl[minVal[1]]);
                pq.push(minVal);
            }
        }
        return res;
    }
};
