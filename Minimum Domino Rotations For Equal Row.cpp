class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
//         int count1=0,count2=0, count3=0,count4=0;
//         int num1=tops[0];
//         int num2=bottoms[0];
//         for(int i=0;i<tops.size();i++){
//             //count 1
//             if(count1!=INT_MAX){
//                 if(tops[i]==num1){
                    
//                 }else if(bottoms[i]==num1){
//                     count1++;
//                 }
//                 else{
//                     count1=INT_MAX;
//                 }
//             }
            
//             //
//              if(count2!=INT_MAX){
//                 if(bottoms[i]==num1){
                    
//                 }else if(tops[i]==num1){
//                     count2++;
//                 }
//                 else{
//                     count2=INT_MAX;
//                 }
//             }
//             //
//              if(count3!=INT_MAX){
//                 if(tops[i]==num2){
                    
//                 }else if(bottoms[i]==num2){
//                     count3++;
//                 }
//                 else{
//                     count3=INT_MAX;
//                 }
//             }
//             // 
//             if(count4!=INT_MAX){
//                 if(tops[i]==num2){
                    
//                 }else if(bottoms[i]==num2){
//                     count4++;
//                 }
//                 else{
//                     count4=INT_MAX;
//                 }
//             }
           
//         }
//          int ans=min(min(count1,count2),min(count3,count4));
//         return ans==INT_MAX? -1: ans;
        
        int n = tops.size();
        int m = bottoms.size();
        map<int,int> mp;
        map<int,int> mp1;
        for(int i=0;i<n;i++){
        mp[tops[i]]++;
        mp1[bottoms[i]]++;    
        }
        int max=INT_MIN;
        int x;
        for(auto y : mp){
        if(y.second>max){
        max=y.second;
        x=y.first;    
            
        }    
            
        }
        int max1 = INT_MIN;
        int x1;
        for(auto c : mp1){
        if(c.second>max1){
        max1=c.second;
        x1=c.first;    
            
        }    
            
        }
        int count=0;
        for(int j=0;j<n;j++){
        if(tops[j] != x && bottoms[j]==x)    
         count++;
        if(tops[j] != x && bottoms[j] != x){
        count=-1;
        break;    
        }    
        }
        int count1=0;
        for(int j=0;j<n;j++){
        if(bottoms[j] != x1 && tops[j]==x1)    
         count1++;
        if(bottoms[j] != x1 && tops[j] != x1){
        count1=-1;
        break;    
        }    
        }
        int ans;
        if(count==-1  && count1==-1)
        ans=-1;
        else if(count==-1 && count1>=0)
        ans=count1;
        else if(count1==-1 && count>=0)
        ans = count;    
        else
        {
            ans = min(count,count1);
        } 
        return ans;
    }
};
