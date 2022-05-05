using ll = long long;
class Solution {
public:
    ll mod = 1e9+7;
    int minVal(int x, int y) { return (x < y)? x: y; } 
    int getMid(int s, int e) { return s + (e -s)/2; } 
    int RMQUtil(int *st, int ss, int se, int qs, int qe, int index, vector<int>& arr) 
    {  
        if (qs <= ss && qe >= se) return st[index]; 
        if (se < qs || ss > qe) return INT_MAX; 
        int mid = getMid(ss, se);
        int in1 = RMQUtil(st, ss, mid, qs, qe, 2*index+1, arr);
        int in2 = RMQUtil(st, mid+1, se, qs, qe, 2*index+2, arr);
        if(in1 == INT_MAX && in2 == INT_MAX) return INT_MAX;
        else if(in1 == INT_MAX) return in2;
        else if(in2 == INT_MAX) return in1;
        return (arr[in1] <= arr[in2] ? in1 : in2);
    } 
    int RMQ(int *st, int n, int qs, int qe, vector<int>& arr) { 
        if (qs < 0 || qe > n-1 || qs > qe) { 
            return -1; 
        } 
        return RMQUtil(st, 0, n-1, qs, qe, 0,arr); 
    } 
    int constructSTUtil(vector<int>& arr, int ss, int se,int *st, int si) { 
        if (ss == se) { 
            st[si] = ss; 
            return ss; 
        } 
        int mid = getMid(ss, se);
        int in1 = constructSTUtil(arr, ss, mid, st, si*2+1);
        int in2 = constructSTUtil(arr, mid+1, se, st, si*2+2);
        st[si] = (arr[in1] <= arr[in2] ? in1 : in2); 
        return st[si]; 
    } 
    int *constructST(vector<int>& arr, int n) { 
        int x = (int)(ceil(log2(n)));
        int max_size = 2*(int)pow(2, x) - 1; 
        int *st = new int[max_size]; 
        constructSTUtil(arr, 0, n-1, st, 0);  
        return st; 
    }
    void query(int l, int r, vector<ll>& pre, int* st, vector<int>& arr, ll& maxv){
        if(l>r) return;
        int in = RMQ(st, arr.size(), l, r, arr);
        ll prod = (pre[r] - (l>0?pre[l-1]:0)) * arr[in];
        maxv = max(maxv, prod);
        query(l, in-1, pre, st, arr, maxv);
        query(in+1, r, pre, st, arr, maxv);
    }
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<ll> pre(n);
        for(int i=0; i<n; i++) pre[i] = nums[i];
        for(int i=1; i<n; i++) pre[i] += pre[i-1];
        ll maxv = LLONG_MIN;
        int* st = constructST(nums, n);
        query(0,n-1,pre,st,nums,maxv);
        maxv %= mod;
        return maxv;
    }
};
