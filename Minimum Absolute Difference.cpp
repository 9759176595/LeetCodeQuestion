class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=INT_MAX;
        // n ko 0 nhi le skte bcz min of arr and n is always 0
        vector<vector<int>> v;
        for(int i=1;i<arr.size();i++){
            n=min(n,arr[i]-arr[i-1]);
        }
        for(int i=1;i<arr.size();i++){
            if(arr[i]-arr[i-1]==n)
            {
             v.push_back({arr[i-1],arr[i]});   
            }
        }
        return v;
    }
};
