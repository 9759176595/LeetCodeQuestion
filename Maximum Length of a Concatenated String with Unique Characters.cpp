class Solution {
public:
    int allunique(string s){
        int freq[26]={0};
        for(int i=0;i<s.size();i++){
            freq[s[i]-97]++;
            if(freq[s[i]-97]>1)  //agar freq 1 se jada to kisi kaam ki nhi
                return 0;
        }
        return s.size();
    }
    int maxLength(vector<string>& arr) {
        int ans=0;
        int n=arr.size();
        long long int total=pow(2,n);  //no of subsequence
        for(int i=0;i<total;i++){
            string curr="";
            for(int j=0;j<n;j++){
                if(i&(1<<j))
                    curr+=arr[j];
            }
            ans=max(ans,allunique(curr));
        }
        return ans;
    }
};
