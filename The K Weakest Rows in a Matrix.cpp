class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
      set<pair<int,int>>m;
       for(int i=0;i<mat.size();i++){
           auto p = accumulate(begin(mat[i]), end(mat[i]), 0);
           m.insert({p,i});
       }
        vector<int>v;
        for(auto it=m.begin();k>0;it++,k--)
            v.push_back(it->second);
        return v;
    }
};
