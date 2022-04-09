class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& pts, int k) {
//         int arr[]
//         priority_queue<pair<int,pair<int,int>>maxh;
//         for(int i=0;i<n;i++){
//             maxh.push({arr[i][0]*arr[i][0]+arr[i][1]*arr[i][1],arr[i][0],arr[i][1]});
            
//             if(maxh.size()>k)
//                 maxh.pop();
//         }
//         while(maxh.size()>0){
//             pair<int,int>p=maxh.top().second();
            
//         }
        
          multimap<int, int> mp;
    for(int i = 0; i < pts.size(); i++)
    {
        int x = pts[i][0], y = pts[i][1];
        mp.insert({(x * x) + (y * y) , i});
    }
     vector<vector<int>>v;
    for(auto it = mp.begin();
             it != mp.end() && k > 0;
             it++, k--)
        v.push_back({pts[it->second][0],pts[it->second][1]});
        return v;
        // cout << "[" << pts[it->second][0] << ", "
        //      << pts[it->second][1] << "]" << "\n";
    }
};
