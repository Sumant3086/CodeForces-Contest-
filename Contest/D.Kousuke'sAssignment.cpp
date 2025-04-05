#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    unordered_map<int,int>lp;
    lp[0]=-1;
    int prefS=0;
    int count=0;
    int cut=-1;
    for(int i=0;i<n;i++){
        prefS+=arr[i];
        if(lp.find(prefS)!=lp.end()){
            if(lp[prefS]>=cut){
                count++;
                cut=i;
                lp.clear();
                lp[0]=i;
            }
        }
        lp[prefS]=i;
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



// incorrect