#include <bits/stdc++.h>
using namespace std;
void solve(){
    long long n,k;
    cin>>n>>k;
    if(n%2==0){
        cout<<(n/(k-1))+(n%(k-1)!=0)<<endl;
    }else{
        n-=k;
        cout<<1+(n/(k-1))+(n%(k-1)!=0)<<endl;
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