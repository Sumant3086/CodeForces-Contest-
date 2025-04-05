#include <bits/stdc++.h>
using namespace std;
int solve(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n+1),b;
    int cut=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==k){
        int cost=-1;
        for(int i=2;i<=n;i+=2){
            if(a[i]!=i/2){
                cost=i/2;
                break;
            }
        }
        if(cost==-1){
            cost=n/2+1;
        }
        cout<<cost<<endl;
    }else{
        int pos=-1;
        for(int i=2;i<=n-k+2;i++){
            if(a[i]!=1){
                pos=i;
                break;
            }
        }
        if(pos==-1){
            int curr=2;
            for(int i=n-k+1;i<=n;i+=2){
                if(a[i]!=curr){
                    break;
                }
                curr++;
            }
            cout<<curr<<endl;
        }else{
            cout<<1<<endl;
        }
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