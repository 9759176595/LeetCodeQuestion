class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        vector<int>ans;
        int sum1=0; int sum2=0;
        int delta;
        set<int>s1;
        for(int i=0;i<B.size();i++){
            sum2+=B[i];
            s1.insert(B[i]);
        }
        for(int j=0;j<A.size();j++){
            sum1+=A[j];
        }
        delta=(sum2-sum1)/2;
        for(int k=0;k<A.size();k++){
            set<int>::iterator it;
            it=s1.find(A[k]+delta);
            if(it!=s1.end()){
                ans.push_back(A[k]);
                ans.push_back(A[k]+delta);
                return ans;
            }
        }
        return ans;
    }
};
