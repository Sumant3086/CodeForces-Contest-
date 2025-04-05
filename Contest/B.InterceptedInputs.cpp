#include <bits/stdc++.h>
using namespace std;
void solve(){
    int k;
    cin>>k;
    vector<int>arr(k);
    for(int i=0;i<k;i++){
        cin>>arr[i];
    }
    int target=k-2;
    for(int n=1;n*n<=target;n++){
        if(target%n==0){
            int m=target/n;
            if(find(arr.begin(),arr.end(),n)!=arr.end() && find(arr.begin(),arr.end(),m)!=arr.end()){
                cout<<n<< " "<<m<<endl;
                break;
            } 
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