class Solution {
public:
     vector<int> ans;
    void find(int n){
        if(n == 0 ){
            ans.push_back(0);
            return ;
        }
        if(n == 1){
            ans.push_back(0);
            ans.push_back(1);
            return ;
        }

        find(n - 1);

        for(int i = ans.size() - 1; i >= 0; i--){
            int temp = ans[i];
            int val = temp + (1 << (n - 1));
            ans.push_back(val);
        }
        return ;
    }
    vector<int> grayCode(int n) {
       find(n);
        return ans; 
    }
};
