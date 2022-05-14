class Solution {
public:
    string digitSum(string s, int k) {
       //1 1 1 1 1 2 2 2 2 2 3
        while(s.size() >k){
            string temp="";
            
            for(int i=0;i<s.size();i++){
                
            int sum=0;
            int count=0;
            
                while( i< s.size()  and k > count){

                    sum= sum+ s[i]-'0';
                    i++;
                    count++;
                    
                }
                temp+=to_string(sum);
                i--;
                
        }
        s= temp;
            
        }
        
        return s; 
    }
};
