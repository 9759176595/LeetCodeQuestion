long long M = pow(10, 9) + 7;
class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
     
     if(k == 1)
         return helper(arr, false);
     
     long long sum = 0;
     for(auto &i : arr)
         sum = (i + sum) % M;
          
     return (helper(arr, true) + (sum >= 0 ? ((k - 2) * sum) % M : 0)) % M;
 }
 
 int helper(vector<int> &arr, bool flag)
 {
     long long tmp = 0, ans = 0;
     for(auto &i : arr)
     {
         tmp = tmp + i;
         if(tmp < 0)
             tmp = 0;
         
         ans = max(ans, tmp) % M;
         tmp %= M;
     }
     
     if(flag)
         for(auto &i : arr)
         {
             tmp = tmp + i;
             if(tmp < 0)
                 tmp = 0;

             ans = max(ans, tmp) % M;
             tmp %= M;
         }
         
     return ans;
        
    }
};
