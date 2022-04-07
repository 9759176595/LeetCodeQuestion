class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
       priority_queue<int>maxh;
        int n=stones.size();
        for(int i=0;i<n;i++){
            maxh.push(stones[i]);
            
        }
        int first,second;
        while(n>1){
            first=maxh.top();
            maxh.pop();
            second=maxh.top();
            maxh.pop();
            n-=2;
            if(first-second>0){
                maxh.push(first-second);
                n+=1;
            }
        }
        if(!maxh.empty())
            return maxh.top();
        return 0;
    }
};
