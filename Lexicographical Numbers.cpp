class Solution {
public:
    void func(int i,int n,vector<int>&v){
        if( i>n)
            return;
        v.push_back(i);
        for(int j=0;j<10;j++){
            func(i*10+j,n,v);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int>v;
        for(int i=1;i<=9;i++){
            func(i,n,v);
        }
        return v;
    }
};
