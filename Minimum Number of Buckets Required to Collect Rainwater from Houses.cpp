class Solution {
public:
//     Intuition:

// To get the minimum number of buckets greedy way is to first place buckets at places where there are houses on both sides and to show that which houses have been covered we will assign them another character(here '@').

//     Then place buckets at remaining required places(where there is a 'H').

//     If we are not able to do so return -1.
    int minimumBuckets(string street) {
         int n=street.size();
       int ans=0;
       for( int i =1 ; i < n-1; i++){
           if(street[i]=='.'){
               if(street[i-1]=='H' && street[i+1]=='H'){
                   ans++;
                   street[i-1]='@';
                   street[i+1]='@';
               }
           }
       } 
        
       for(int i=0 ; i < n ;i++){
           if(street[i]=='.'){
               if(i < n-1 && street[i+1]=='H'){
                   ans++;
                   street[i+1]='@';
               }
               else if(i>0 && street[i-1]=='H'){
                   ans++;
                   street[i-1]='@';
               }
           }
       } 
       
       for(int i=0; i < n ;i++){
           if(street[i]=='H') return -1;
       }  
       return ans; 
    }
};
