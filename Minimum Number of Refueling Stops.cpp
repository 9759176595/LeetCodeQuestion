class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
       int ans=0;
        long range= startFuel;
        priority_queue<long> pq;
        int i=0;
        while(i<stations.size()){
            if(range>= target) return ans;                                // we can reach target
            if(range<stations[i][0]){                                         // we refuel , but stay on the same index of pump, as we need to make sure that, we reached till its position
                if(pq.empty()) return -1;
                range+= pq.top();
                pq.pop();
                ans++;
                continue;
            }
            else                                                         // we can pass this pump , no refuel needed, store in queue for future
                pq.push(stations[i][1]);
            i++;
        }
        while(range<target && !pq.empty()){             // now we check , if we can reach the target or not
            range+= pq.top();
            pq.pop();
            ans++;
        }
        return range>=target ? ans: -1;
    }
};
