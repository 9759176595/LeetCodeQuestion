class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        //--------MEthod 1
       // if(arr[0]>k) 
       //     return k;
       //  int num=k;
       //  for(int a:arr){
       //      if(a<=num){
       //          num++;
       //      }
       //      else{
       //          break;
       //      }
       //  }
       //  return num;
        
        //----method 2 binary search
        int lo=0;
        int hi=arr.size()-1;
        int closestMid=0;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(arr[mid]-(mid+1)<k){
                closestMid=mid+1;
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        return (k+closestMid);
    }
};
