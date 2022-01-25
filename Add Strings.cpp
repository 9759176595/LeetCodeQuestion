class Solution {
public:
    string addStrings(string num1, string num2) {
        int i=num1.size()-1;
        int j=num2.size()-1;
         string res="";
        int car=0;
        while(i>=0 || j>=0){
            if(i>=0)
                car+=num1[i--]-'0';
            
            if(j>=0)
                car+=num2[j--]-'0';
            
            res=to_string(car%10)+res;
            car/=10;
        }
        return car? "1"+res: res;
    }
};
