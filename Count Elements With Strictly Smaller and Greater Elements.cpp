class Solution {
public:
    int countElements(vector<int>& num) 
    {
        int count=0;
        int t=num.size();
        sort(num.begin(),num.end());
         for(int i=1;i<t-1;i++)   
         {
             int res1=*max_element(num.begin()+i, num.end());
             int res2=*min_element(num.begin(),num.begin()+i-1);
             if(res2<num[i] && res1>num[i])
                 count++;
         }
        return count;
    }
};
