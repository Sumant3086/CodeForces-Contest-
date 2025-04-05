#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>a(m);
    set<int>s2,s3;
    for(int i=1;i<=n;i++){
        s3.insert(i);
    }
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    vector<int>q(k);
    for(int i=0;i<k;i++){
        cin>>q[i]; 
        s2.insert(q[i]);
    }
    string res;
    if(s3==s2){
        for(int i=0;i<m;i++){
            res+='1';
        }
        cout<<res<<endl;
        return;
    }
    if(k<n-1){
        for(int i=0;i<m;i++){
            res+='0';
        }
        cout<<res<<endl;
        return;
    }
    for(int i=0;i<m;i++){
        if(s2.find(a[i])==s2.end()){
            res+='1';
        }else{
            res+='0';
        }
    }
    cout<<res<<endl;  
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}