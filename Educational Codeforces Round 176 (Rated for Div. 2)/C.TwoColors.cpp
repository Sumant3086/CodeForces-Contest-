#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int>arr(m);
    for(int i=0;i<m;i++){
        cin>>arr[i];
    } 
    sort(arr.begin(),arr.end());
    long long way=0;
    for(int ll=1;ll<n;ll++){ 
        int rl=n-ll;
        int li=lower_bound(arr.begin(),arr.end(),ll)-arr.begin();
        int lc=m-li;
        int ri=lower_bound(arr.begin(),arr.end(),rl)-arr.begin();
        int rc=m-ri;
        int bi=lower_bound(arr.begin(),arr.end(),max(ll,rl))-arr.begin();
        int bc=m-bi;
        way+=(long long)lc*rc-bc;
    }
    cout<<way<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
} 

