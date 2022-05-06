class Solution {
public:
    pair<int,int>memo[41][41];
    pair<int,int>recur(int start,int end,vector<int>&arr){
        if(memo[start][end].first!=-1) return memo[start][end];
       else if(start==end) return memo[start][end]= {arr[start],0};
        else{
            int nonLeafSum=INT_MAX;
            int maxLeaf=INT_MIN;
            
            for(int i=start;i<end;i++){
                pair<int,int>p1=recur(start,i,arr);
                pair<int,int>p2=recur(i+1,end,arr);
                maxLeaf=max({maxLeaf,p1.first,p2.first});
                nonLeafSum=min({nonLeafSum,p1.first*p2.first+p1.second+p2.second});
            }
            return memo[start][end]={maxLeaf,nonLeafSum};
        }
    }
    int mctFromLeafValues(vector<int>& arr) {
        for(int i=0;i<41;i++){
            for(int j=0;j<41;j++)
                memo[i][j]={-1,-1};
        }
        return recur(0,arr.size()-1,arr).second;
    }
};
