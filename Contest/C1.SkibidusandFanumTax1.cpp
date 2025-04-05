#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int>b(m);
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    int bVal=b[0];
    int prev=INT_MIN;
    for(int i=0;i<n;i++){
        int notTake=a[i];
        int take=bVal-a[i];
        if(notTake>=prev && take>=prev){
            a[i]=min(notTake,take);
        }else if(take>=prev){
            a[i]=take;
        }else if(notTake>=prev){
            a[i]=notTake;
        }else{
            cout<<"NO"<<endl;
            return;
        }
        prev=a[i];
    }
    cout<<"YES"<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}