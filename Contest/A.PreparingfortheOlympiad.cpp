#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int train=a[n-1];
    for(int i=1;i<n;i++){
        if(a[i-1]>b[i]){
            train+=(a[i-1]-b[i]);
        }
    }
    cout<<train<<endl;  
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}