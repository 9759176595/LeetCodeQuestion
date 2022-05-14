class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
         unordered_map<string, vector<int>> mp;
         return diffWaysToCompute(expression, mp);
    }
    vector<int> diffWaysToCompute(string expression, unordered_map<string, vector<int>> &mp)
{
    int n = expression.size();
    if(n <= 2)
        return vector<int> {stoi(expression)};
    
    if(mp.find(expression) != mp.end())
        return mp[expression];
    
    vector<int> ans;
    for(int i = 0; i < n; i++)
        if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*')
        {
            vector<int> tmp1 = diffWaysToCompute(expression.substr(0, i), mp);
            vector<int> tmp2 = diffWaysToCompute(expression.substr(i + 1), mp);
            
            for(auto &a : tmp1)
                for(auto &b : tmp2)
                    ans.push_back(expression[i] == '+' ? a + b : expression[i] == '-' ? a - b : a * b);
        }
    
    return mp[expression] = ans;
}
};
