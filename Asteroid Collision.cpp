class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
       int n = asteroids.size();
        stack<int>st;
        vector<int>ans;
        for(int i = 0 ; i < n ;  i++){
            if(asteroids[i] > 0){
                st.push(asteroids[i]);
            }else{
                int val = abs(asteroids[i]);
                while(!st.empty() and st.top() <= val){
                    if(st.top() == val){
                        val = 0;
                        st.pop();
                        break;
                    }
                    st.pop();
                }
                if(st.empty() and val){
                    ans.push_back(asteroids[i]);
                }
            }
        }
        stack<int>temp;
        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }
        while(!temp.empty()){
            ans.push_back(temp.top());
            temp.pop();
        }
        return ans;
    }
};
