#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,k,p;
    cin>>n>>k>>p;
    if(k>n*p || k<-n*p){
        cout<<"-1"<<endl;
    }else{
        cout<<(abs(k)+p-1)/p<<endl;
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