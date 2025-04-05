#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,x;
    cin>>n>>x;
    vector<int>arr(n);
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    if(n==1){
        if(arr[0]==x)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }else{
        if(sum==x*n)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
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