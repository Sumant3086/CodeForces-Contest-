#include <bits/stdc++.h>
using namespace std;
void solve(){
    int l,r,d,u;
    cin>>l>>r>>d>>u;
    if(l==r && r==d && d==u){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}