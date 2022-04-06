class Solution {
public:
    string convertToString(vector<char>&a){
        string s="";
        for(int i=0;i<a.size();i++){
            s+=a[i];
        }
        return s;
    }
    void rotateArray(vector<char>&arr){
        char ch=arr[0];
        for(int i=0;i<arr.size()-1;i++){
            arr[i]=arr[i+1];
        }
        arr[arr.size()-1]=ch;
    }
    string orderlyQueue(string s, int k) {
        vector<char>res;
        for(int i=0;i<s.length();i++){
            res.push_back(s[i]);
        }
        string ans=s;
        if(k>1){
            sort(res.begin(),res.end());
            return convertToString(res);
        }
         else{
             for(int i=0;i<s.length();i++){
                 rotateArray(res);
                 int diff=ans.compare(convertToString(res));
                 if(diff>0){
                     ans=convertToString(res);
                 }
             }
         }   
        return ans;
    }
};
