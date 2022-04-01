class Solution {
public:
    int maximumProduct(vector<int>& A) {
      sort(A.begin(),A.end());
        int N=A.size();
        int P1=A[N-1]*A[0]*A[1];
        int P2=A[N-1]*A[N-2]*A[N-3];
        return max(P1,P2);
    }
};
