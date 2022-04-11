class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        /* Adjacency list =>
            NOTE 1: We understand that the adjacency list should show edge between strings.
            NOTE 2: It is a weighted directed graph.
                i.e. a/b = 2.0 needs to be represented as (a---2.0--->b) 
            
            Every element should point to its divisor and the value.
            So, we use map for creating the list with key as the dividend string
            The value associated is a pair of string and double value.
            Since one key have multiple associated values, we make the value also as a map object.
            
            ........
            When creating a list, 
                    suppose a/b = 2.0
                    => a/b = 2.0 , b/a = 1/2.0 , a/a = 1.0, b/b = 0
                    Hence for each edge, add these three combinations in the map.
                    => mp[a][b] = 2.0, mp[b][a] = 1/2.0 , mp[a][a] = 1.0, mp[b][b] = 2.0
                    
        */
        
        unordered_map <string, unordered_map <string, double>> mp;
        for(int i = 0; i<equations.size(); i++){
            double v = values[i];
            mp[equations[i][0]][equations[i][1]] = v;
            mp[equations[i][1]][equations[i][0]] = 1/v;
            mp[equations[i][0]][equations[i][0]] = 1.0;
            mp[equations[i][1]][equations[i][1]] = 1.0;
        }
        
        /* To solve the queries, 
                mp[a][b] = a/b value
              & mp[b][c] = b/c value
              
         => mp[a][c] should equal a/c value
                                = (a/b) * (b/c) value
         => mp[a][c] = mp[a][b] * mp[b][c] */
        
        for(auto i: mp){
            for(auto j : mp[i.first]){
                for(auto k: mp[i.first])
                    mp[j.first][k.first] = mp[j.first][i.first] * mp[i.first][k.first];
            }
        }
        
        /* Solving Queries one by one */
        
        vector <double> v;
        for(auto i: queries){
            string from = i[0];
            string to = i[1];
            if((mp.find(from)!=mp.end()) && (mp[from].find(to)!=mp[from].end()))
                v.push_back(mp[from][to]);
            else
                v.push_back(-1.0);
        }
        
        return v;
    }
};
