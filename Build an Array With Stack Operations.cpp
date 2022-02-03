class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int counter=1;   // ->n
        int i=0;  //iterate through the target array
        while(i<target.size()){
            if(counter==target[i]){
                ans.push_back("Push");
                i+=1;
            }else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            counter+=1;
        }
        return ans;
        
    }
};
