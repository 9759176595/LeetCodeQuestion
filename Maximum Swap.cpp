class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        string new1=s;
        for(int i=0;i<new1.size();i++){
            for(int j=i+1;j<new1.size();j++){
                swap(new1[i],new1[j]);
                int max=stoi(new1);
                
                if(max>num){
                    num=max;
                }
                new1=s;
            }
        }
        return num;
    }
};
