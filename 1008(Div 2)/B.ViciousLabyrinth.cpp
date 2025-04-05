#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    long long k;
    cin>>n>>k;
    vector<int>arr(n+1); 
    k%=2;
    if(k==1){
        for(int i=1;i<=n;i++){
            if(i==n){
                arr[i]=n-1;
            }else{
                arr[i]=n;
            }
        }
    }else{
        if(n==2){
            arr[1]=2;
            arr[2]=1;
        }else{
            arr[n-1]=n;
            arr[n]=n-1;
            for(int i=1;i<n-1;i++){
                arr[i]=n-1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<(i<n?" ":"");
    }
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}