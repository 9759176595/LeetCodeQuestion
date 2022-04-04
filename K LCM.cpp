#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.141592653589
#define MOD 1000000007
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0)
#define deb(x) cout<<"[ "<<#x<<" = "<<x<<"] " 
 
 
void solve(){ 
    int n,k;cin>>n>>k;
    while(k>3)
    {
        cout<<"1 ";
        k--;
        n--;
    }
 
    if(n&1)
    {
        cout<<1<<" "<<n/2<<" "<<n/2;
    }
    else{
        if(n%4==0)
        {
            cout<<n/4<<" "<<n/4<<" "<<n/2;
        }
        else{
           cout<<2<<" "<<(n/2)-1<<" "<<(n/2)-1;
        }
    }
 
 
 
    cout<<"\n";
 
}
 
 
signed main(){
FAST_IO;
int t=1;
cin>>t;
while(t--)
solve();
return 0;
}
