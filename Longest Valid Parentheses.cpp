class Solution {
public:
    int longestValidParentheses(string s) {
       stack<int> st;
        int mx=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                st.push(i);
            else
            {
                if(st.empty())
                {
                   st.push(i);
                }
                else if(s[st.top()]==')')
                {
                    st.push(i);
                }
                else
                {
                    st.pop();
                    if(!st.empty())
                        mx=max(mx,i-st.top());
                    else
                        mx=max(mx,i+1);
                }
                
            }
        }
        return mx; 
    }
};
