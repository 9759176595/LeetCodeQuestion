class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>end_idx(26,0);
        for(int i=0;i<s.length();i++){
            end_idx[s[i]-'a']=i;
        }
        vector<int>result;
        int start=0,end=0;
        for(int i=0;i<s.length();i++){
           end=max(end,end_idx[s[i]-'a']);
          if(i==end){//all the characters of current partition included
              result.push_back(i-start+1);
              start=i+1;
          }
        }
        return result;
    }
};
