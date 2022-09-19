class Solution {
public:
    vector<string> split(string &s,char ch) //general split function
{
    int pos = s.find(ch);
    vector<string> ans;
    int start = 0;
    while(pos!=-1)
    {
        ans.push_back(s.substr(start,pos-start));
        start = pos +1;
        pos = s.find(ch,start);
    }
    
    ans.push_back(s.substr(start));
    
    return ans;
}
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>> map;
    vector<vector<string>> ans;
    for(auto info : paths)
    {
        auto path = split(info,' '); 
        string dir=  path[0]; //path of directory
        
        for(int i=1;i<path.size();i++)
        {
            auto file_data = split(path[i],'(');
            string file = file_data[0]; //file name
            string data = file_data[1]; //data in it
            
            map[data].push_back(dir+'/'+file); //appending full path including file name
          
        }
    }
    
    for(auto [k,v]: map)
    {
        if(v.size()>1) // appending to answer only if duplicated files are present
            ans.push_back(v);
    }
    
    return ans;
}
    
};
