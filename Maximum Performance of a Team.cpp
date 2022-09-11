class Solution {
public:
//     In this type of questions we have to fix a parameter, here we can fix minimum efficiency
// If we sort {efficiency,speed} in decreasing efficiency, we know for ith efficiency, since everything from 1 to i-1
// is more than it, ith is the minimum. So from 1 to i-1 if we have the sum of best k-1 speeds we can team them
// with ith and we do this for every i and keep taking its maximum.
// Note that to find topk sum we can use a heap and maintain its size as less than equal to k and also
// keep track of sum of the elements present in heap.
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
         priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0, ans = 0;
        const int m = 1e9 + 7;
        vector<vector<int>> pairs(n, vector<int> (2, 0));
        for(int i = 0; i < n; i++) pairs[i] = {efficiency[i], speed[i]};
        sort(pairs.rbegin(), pairs.rend());
        for(int i = 0; i < n; i++){
            sum += pairs[i][1];
            pq.push(pairs[i][1]);
            ans = max(ans,sum * pairs[i][0]);
            if(pq.size() >= k){
                sum -= pq.top();
                pq.pop();
            }
        }
        return ans%(m);
    }
};
