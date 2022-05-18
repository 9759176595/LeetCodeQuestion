class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        vector<int>ans;
        int t=1;
        while(1){
            if(memory1>=t  || memory2>=t){  //sufficient memory to remove
                if(memory1>=memory2)
                    memory1-=t;
                else memory2-=t;
            }
            else{ //crash case
                ans.push_back(t);
                ans.push_back(memory1);
                ans.push_back(memory2);
                return ans;
            }
            t++;
        }
        return ans;
    }
};
