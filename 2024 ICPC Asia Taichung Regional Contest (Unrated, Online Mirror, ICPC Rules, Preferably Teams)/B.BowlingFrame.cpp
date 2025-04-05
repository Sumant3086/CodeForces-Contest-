#include <bits/stdc++.h>
using namespace std;
void solve(){
    long long w,b;
    cin>>w>>b;
    long long k=1; 
    while((k*(k+1))/2<=w+b){
        k++;
    }
    k--;
    cout<<k<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}