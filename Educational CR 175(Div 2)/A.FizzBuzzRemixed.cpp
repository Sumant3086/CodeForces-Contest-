#include <bits/stdc++.h>
using namespace std;
void solve(){
    long long n;
    cin>>n;
    long long count=(n/15)*3;
    long long rem=n%15;
    if(rem>=0)count+=min(rem+1,3LL);
    cout<<count<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}