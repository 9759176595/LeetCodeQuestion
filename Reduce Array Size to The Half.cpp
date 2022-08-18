class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size(); int ans=0,cnt=0;
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
            //cout<<m[arr[i]]<<" "<<i<<endl;
           // if(m[arr[i]]>=n/2) return 1;
        }
        vector<int>v;
        for(auto x: m){
            v.push_back(x.second);
        }
        sort(v.begin(),v.end());
         for(int i=v.size()-1;i>=0;i--){
            cnt++;
            ans+=v[i];
            if(ans>=n/2)return cnt;
        }
        return 0;
    }
};
