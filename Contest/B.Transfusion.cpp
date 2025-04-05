#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    long long evenSum=0;
    long long oddSum=0;
    long long oddP=n/2;
    long long evenP=(n+1)/2;
    for(int i=0;i<n;i++){
        if(i%2==0){
            evenSum+=arr[i];
        }else{
            oddSum+=arr[i];
        }
    }
    if(evenSum%evenP==0 && oddSum%oddP==0 && evenSum/evenP==oddSum/oddP){
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
 