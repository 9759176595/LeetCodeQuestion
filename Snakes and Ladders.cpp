class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        int count=0;
        queue<int> q;
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        q.push(1);
        vis[n-1][0]=true;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int cur=q.front();
                q.pop();
                if(cur==n*n)return count;
                for(int i=1;i<=6;i++){
                    if(cur+i>n*n)break;
                    pair<int,int> p=getCordinateValue(n,cur+i,board);
                    int r=p.first;
                    int c=p.second;
                    cout<<r<<" "<<c<<endl;
                    if(vis[r][c])continue;
                    vis[r][c]=true;
                    if(board[r][c]==-1)q.push(cur+i);
                    else q.push(board[r][c]);
                }
            }
            count++;
        }
        return -1;   
    }
    
     pair<int,int> getCordinateValue(int n,int val,vector<vector<int>>& board){
        int r=n-(val-1)/n -1;
        int c=(val-1)%n;
        if(r%2==n%2){
            c=n-1-c;
        }
        pair<int,int> p(r,c);
        return p;
     }
};
