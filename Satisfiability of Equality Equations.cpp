class Solution {
    int find(int a,vector<int>& parent)
{
    if(parent[a]==-1)
        return a;
    else
        return parent[a]=find(parent[a],parent);
}

void unions(int a,int b,vector<int>& parent,vector<int>& rank)
{
    a=find(a,parent);
    b=find(b,parent);
    if(a==b)
        return;
    if(rank[a]>=rank[b])
    {
        rank[a]+=rank[b];
        parent[b]=a;
    }
    else
    {
        rank[b]+=rank[a];
        parent[a]=b;
    }
}
public:
    bool equationsPossible(vector<string>& equations) {
       vector<int> parent(26,-1);
    vector<int> rank(26,1);
    for(auto str:equations)
    {
        if(str[1]=='=')
            unions(str[0]-'a',str[3]-'a',parent,rank); // forming DSU for type 1 equation
    }
    for(auto str:equations)
    {
        if(str[1]=='!')
        {
            int a=find(str[0]-'a',parent); // checking whether they belong to same component or not
            int b=find(str[3]-'a',parent);
            if(a==b)
                return false; // if they belong return false
        }
    }
    return true; 
    }
};
