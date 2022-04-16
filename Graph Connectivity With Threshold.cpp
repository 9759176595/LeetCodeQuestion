class UnionFind{
    vector<int>size,parent;
    public:
    UnionFind(int n){
        size.resize(n);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int find(int v){
        if(v==parent[v])
            return v;
        return parent[v]=find(parent[v]);  //path compression
    }
    bool Union(int v1,int v2){
        int p1=find(v1);
        int p2=find(v2);
        if(p1==p2)
            return false;
        if(size[p1]>size[p2]){
            size[p1]+=size[p2];
            parent[p2]=p1;
        }
        else{
            size[p2]+=size[p1];
            parent[p1]=p2;
        }
        return true;
    }
};
class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        UnionFind uf(n+1);
        for(int i=threshold+1;i<=n;i++){
            for(int j=2*i;j<=n;j+=i){
                    uf.Union(i,j);  
            }
        }
        vector<bool>ans;
        int pi,pj;   //parent i, parent j
        for(auto& q: queries){
            pi=uf.find(q[0]);
            pj=uf.find(q[1]);
            
            ans.push_back(pi==pj);
        }
        return ans;
    }
};
