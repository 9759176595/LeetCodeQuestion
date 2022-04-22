class Solution {
public:
    int totalHammingDistance(vector<int>& a) {
        //cout<<bitset<32>(5).to_string()<<endl;
        int n=a.size();
        int ans=0;
        
        for(int i=0;i<32;i++){
            int one=0,z=0;
            int k=1<<i;
            for(int j=0;j<n;j++){
                if(a[j]&k)  //bit is set
                    one++;
                if((a[j]&k)==0)  //bit is unset
                    z++;
            }
            if(one==n || z==n)
                continue;
            else
                ans+=(one*z);
        }
        return ans;
    }
};
