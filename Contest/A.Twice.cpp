#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,x;
    cin>>n;
    int count=0;

    vector<int>freq(n+1,0);
    for(int i=0;i<n;i++){
        cin>>x;
        freq[x]++;
    }
    
    for(int i=1;i<=n;i++){
        count+=freq[i]/2;
    }
    cout<<count<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}