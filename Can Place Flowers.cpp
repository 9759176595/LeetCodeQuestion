class Solution {
    public: 
     bool canPlaceFlowers(vector<int> flowerbed, int n) {
        int cnt=0;
         // if(flowerbed.size()==1 && flowerbed[0]==0){
         //     return 
         // }
         int j;
         for(j=0;j<flowerbed.size();j++){
             if(flowerbed[j]==1){
                 break;
             }
         }
         if(j==flowerbed.size()){
             if(j%2==0 && j/2>=n){
                 return 1;
             }
             else if(j%2==1 && (j/2+1>=n)){
                 return 1;
             }
             else 
                 return 0;
         }
         
         if(flowerbed.size()==1){
             if(flowerbed[0]==0 && n==1){
                 return 1;
             }else if(flowerbed[0]==1 && n==1){
                 return 0;
             }else if(flowerbed[0]==1 && n==0){
                 return 1;
             }
             else{
                 return 1;
             }
             
         }
//         for(int i=1;i<flowerbed.size();i++){
//             if(flowerbed[i]==0 && (flowerbed[i-1]==0 && flowerbed[i+1]==0)){
//                 cnt++;
//             }
//         }
//         if(cnt==n){
//             return 1;
//         }
       
//             return 0;
         vector<int> v;
         
         for(int i=0;i<flowerbed.size();i++){
             if(flowerbed[i]==1){
                 v.push_back(i);
             }
         }
         int z=v.size();
         int res1=v[0];
         int res2=flowerbed.size()-1-v[z-1];
         int res=0;
         res=res+res1/2;
         res=res+res2/2;
         //cout<<res;
         for(int i=1;i<z;i++){
             int val=v[i]-v[i-1]-1;
             if(val/2>=1 &&val%2==1)
                 res+=val/2;
              if(val/2>=2 &&val%2==0)
                 res+=val/2-1;
         }
        if(res>=n){
            return 1;
        }
        return 0;
    }
};
