class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string,int> s1;
        map<string,int>s2;
        for(int i=0;i<list1.size();i++){
            s1.insert({list1[i],i});
        }
        for(int i=0;i<list2.size();i++){
            s2.insert({list2[i],i});
        }
        int res=INT_MAX;
        vector<string>vec;
        for(int i=0;i<list1.size();i++){
           if(s1.find(list1[i])!=s1.end() && s2.find(list1[i])!=s2.end()) 
           {
              int val=res;  
              res=min(res,s1[list1[i]]+s2[list1[i]]);
           }
        }
        for(int i=0;i<list1.size();i++)
        {
           if(s1.find(list1[i])!=s1.end() && s2.find(list1[i])!=s2.end()) 
           {
               if(s1[list1[i]]+s2[list1[i]]==res)
                   vec.push_back(list1[i]);
           }
        }
        return vec;
    }
};
