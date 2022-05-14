class Solution {
public:
    string convertToBase7(int num) {
          if(num == 0) return "0";
        bool is_negative = false;
        if(num < 0) is_negative = true;
        num = abs(num);
        string answer = "";
        while(num > 0){
            answer = to_string(num%7) + answer;
            num /= 7;
        }
        if(is_negative) answer = '-' + answer;
        return answer;
    }
};
