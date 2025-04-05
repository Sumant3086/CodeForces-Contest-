#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    if(n==1){
        cout<<k<<endl;
        return;
    }
    for(int j=1;j<=n;j++){
        if(j==1 || j==n){
            cout<<k<<" ";
        }else{
            cout<<0<<" ";
        }
    }
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}