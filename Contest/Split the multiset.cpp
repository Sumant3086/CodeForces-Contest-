#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define read(a)for(auto &i:a)cin>>i 
#define mod 1000000007
signed main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t=1;
cin>>t;
while(t--){
    int n;
    cin>>n;
    int op;
    cin>>op;
    if(n==1){
        cout<<0<<endl;
        continue;
    }
    int res=0;
    op--;
    while(n>1){
        n=n-op;
        res++;
    }
    cout<<res<<endl;
}

return 0;
}