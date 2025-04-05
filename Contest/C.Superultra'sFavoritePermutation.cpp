#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    if(n<=4){
        cout<<"-1"<<endl;
    }else{
        cout<<1<<" "<<3<<" ";
        for(int  i=7;i<=n;i+=2){
            cout<<i<<" ";
        }
        cout<<5<<" "<<4<<" "<<2<<" ";
        for(int  i=6;i<=n;i+=2){
            cout<<i<<" ";
        }
        cout<<endl;
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