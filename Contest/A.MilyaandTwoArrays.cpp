#include <bits/stdc++.h>
using namespace std; 
void solve(){
    int n;
    cin>>n;
    vector<int>a(n),b(n),c(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    unordered_set<int>sum;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sum.insert(a[i]+b[j]);
        }
    }
    if(sum.size()>=3){
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