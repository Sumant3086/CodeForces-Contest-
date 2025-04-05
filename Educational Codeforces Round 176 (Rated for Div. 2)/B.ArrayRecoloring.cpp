#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    } 
    sort(arr.rbegin(),arr.rend());
    long long sum=0;
    for(int i=0;i<k;i++){
        sum+=arr[i];
    }
    sum+=*min_element(arr.begin(),arr.begin()+k+1);
    cout<<sum<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
} 

