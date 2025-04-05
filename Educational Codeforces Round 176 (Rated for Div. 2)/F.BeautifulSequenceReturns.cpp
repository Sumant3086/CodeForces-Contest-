#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int>arr(m);
    for(int i=0;i<m;i++){
        cin>>arr[i];
    } 
    vector<int>al(n+1,0);
    for(int l=1;l<=n;l++){
        for(int i=0;i<m;i++){
            if(arr[i]>=l){
                al[l]++;
            }
        }
    }
    long long way=0;
    for(int ll=1;ll<n;ll++){ 
        int rl=n-ll;
        int lc=0;
        for(int i=0;i<m;i++){
            if(arr[i]>=ll){
                way+=al[rl];
                if(arr[i]>=rl){
                    way--;
                }
            }
        } 
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

