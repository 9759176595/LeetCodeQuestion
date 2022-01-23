class Solution {
public:
    vector<int> rearrangeArray(vector<int>& num) 
    {
       vector<int> t1;
       vector<int>t2;
       for(int i=0;i<num.size();i++)
       {
           if(num[i]<0)
               t1.push_back(num[i]);
           if(num[i]>0)
               t2.push_back(num[i]);
       }
       vector<int> ans;
       for(int i=0;i<t1.size();i++)
       {
           ans.push_back(t2[i]);
           ans.push_back(t1[i]);
       }
        return ans;
    }
};
