class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> result;
        unordered_set<float> _set;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                float fraction= float(i)/j;
                if(_set.find(fraction)==_set.end()){
                    result.push_back(to_string(i)+"/"+to_string(j));
                    _set.insert(fraction);
                }
            }
        }
        return result;
    }
};
